PORTNAME=	trurl
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	0.7
CATEGORIES=	misc www

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Command line tool for URL parsing and manipulation
WWW=		https://github.com/curl/trurl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python:test
USE_GITHUB=	yes
GH_ACCOUNT=	curl

MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-lcurl" \
		LDLIBS="-L${LOCALBASE}/lib" \
		MANDIR="${PREFIX}/man/man1"

ALL_TARGET=	${PORTNAME}
TEST_TARGET=	test

PLIST_FILES=	bin/trurl \
		man/man1/trurl.1.gz

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/trurl

.include <bsd.port.mk>
