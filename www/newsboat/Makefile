# Created by: arved
# $FreeBSD$

PORTNAME=	newsboat
PORTVERSION=	2.11.1
DISTVERSIONPREFIX=	r
CATEGORIES=	www

MAINTAINER=	mt@markoturk.info
COMMENT=	RSS feed reader for the text console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libstfl.so:devel/stfl \
		libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c

USES=		compiler:c++11-lib gettext gmake iconv:translit ncurses \
		pkgconfig sqlite shebangfix ssl
USE_GITHUB=	yes
USE_CXXSTD=	gnu++11
USE_GNOME=	libxml2

MAKE_ARGS=	mandir=${PREFIX}/man prefix=${PREFIX}

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's,fail "ncursesw",true,; s,fail "libcrypto",true,' \
		${WRKSRC}/config.sh
	${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB} -lcrypto -lncursesw|;s|-Werror||' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*boat

.include <bsd.port.mk>
