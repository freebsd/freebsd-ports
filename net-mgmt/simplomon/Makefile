PORTNAME=	simplomon
DISTVERSION=	g20250224
CATEGORIES=	net-mgmt dns net
MAINTAINER=	dch@FreeBSD.org
COMMENT=	Simple network status and uptime monitoring tool
WWW=		https://github.com/berthubert/simplomon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		nlohmann-json>0:devel/nlohmann-json \
		xxd>0:sysutils/xxd

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfmt.so:devel/libfmt \
		libnghttp2.so:www/libnghttp2
USES=		cmake:indirect compiler:c++17-lang llvm:18,build lua:53,build \
		meson ninja pkgconfig python:build sqlite ssl

USE_GITHUB=	yes
GH_ACCOUNT=	berthubert
GH_TAGNAME=	b4fea5b # https://github.com/berthubert/simplomon/pull/58
GH_TUPLE=	berthubert:sqlitewrite:a2c2ee:sqlitewrite \
		ahuPowerDNS:simplesocket:3af5e1d:simplesocket \
		yhirose:cpp-httplib:v0.13.1:httplib

USE_RC_SUBR=	simplomon

MESON_ARGS+=	--default-library=static \
		--prefer-static \
		--strip \
		--wrap-mode=nodownload

SUB_FILES=	pkg-message simplomon
SUB_LIST=	ETCDIR=${ETCDIR}

PLIST_FILES=	bin/simplomon
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-extract:
	${RLN} ${WRKDIR}/sqlitewrite-* ${WRKSRC}/subprojects/sqlitewriter
	${RLN} ${WRKDIR}/simplesocket-* ${WRKSRC}/subprojects/simplesockets
	${RLN} ${WRKDIR}/cpp-httplib-* ${WRKSRC}/subprojects/

post-build:
	${RM} -rf ${WRKDIR}/_build/meson-private ${WRKSRC}/subprojects

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/simplomon \
		${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
