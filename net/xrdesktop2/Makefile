PORTNAME=	xrdesktop2
PORTVERSION=	2.00
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://BSDforge.com/projects/source/net/xrdesktop2/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	GTK2 frontend for Rdesktop
WWW=		https://BSDforge.com/projects/net/xrdesktop2/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		rdesktop:net/rdesktop

USES=		desktop-file-utils perl5 shebangfix tar:xz
SHEBANG_FILES=	xrdesktop
CONFLICTS=	xrdesktop-1*

NO_ARCH=	yes
NO_BUILD=	yes
DOCS=		Changelog README
PIXMAPS=	x-remote-desktop-256.png x-remote-desktop-128.png \
		x-remote-desktop-48.png

PLIST_FILES=	bin/xrdesktop \
		share/applications/xrdesktop2.desktop \
		share/doc/xrdesktop2/Changelog \
		share/doc/xrdesktop2/README \
		share/pixmaps/x-remote-desktop-128.png \
		share/pixmaps/x-remote-desktop-256.png \
		share/pixmaps/x-remote-desktop-48.png

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xrdesktop ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${PIXMAPS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/xrdesktop2.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${WRKSRC}/${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
