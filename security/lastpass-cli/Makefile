# Created by: Thomas Hurst <tom@hur.st>
# $FreeBSD$

PORTNAME=	lastpass-cli
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	tom@hur.st
COMMENT=	LastPass command line interface tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gmake pkgconfig
USE_GNOME=	libxml2
USE_OPENSSL=	yes

USE_GITHUB=	YES
GH_ACCOUNT=	lastpass

PLIST_FILES=	bin/lpass
MAKE_ENV+=	MANDIR=${MANPREFIX}/man

OPTIONS_DEFINE=		MANPAGES PINENTRY XCLIP XSEL
OPTIONS_DEFAULT=	MANPAGES
PINENTRY_DESC=		Use pinentry for password entry
XCLIP_DESC=		Use xclip for interacting with X11 clipboard
XSEL_DESC=		Use xsel for interacting with X11 clipboard

MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
MANPAGES_ALL_TARGET=	all doc-man
MANPAGES_INSTALL_TARGET=install install-doc
MANPAGES_PLIST_FILES=	${MANPREFIX}/man/man1/lpass.1.gz

PINENTRY_RUN_DEPENDS=	pinentry:security/pinentry
XCLIP_RUN_DEPENDS=	xclip:x11/xclip
XSEL_RUN_DEPENDS=	xsel:x11/xsel

post-extract:
	@${REINPLACE_CMD} -e 's/-Wno-language-extension-token//g' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lpass

.include <bsd.port.mk>
