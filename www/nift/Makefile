PORTNAME=	nift
DISTVERSIONPREFIX=	v
DISTVERSION=	4.12.0
CATEGORIES=	www

MAINTAINER=	info@babaei.net
COMMENT=	Cross-platform open source website generator
WWW=		https://www.nift.dev

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	git>0:devel/git

USES=		compiler:c++17-lang gmake python:build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	nift-dev
GH_PROJECT=	nift

SHEBANG_FILES=	scripts/build_vendored_libffi.sh

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS} -std=c++17 -pthread" \
		LDFLAGS="${LDFLAGS}"
TEST_TARGET=	test

CPPFLAGS+=	-Isrc -Iinclude -Iminifypp/include -Iminifypp/src \
		-Imarkuppp/include -Imarkuppp/vendor/cmark

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES=	bin/nift

post-install:
	${STRIP_CMD}	${STAGEDIR}${PREFIX}/bin/nift

.include <bsd.port.mk>
