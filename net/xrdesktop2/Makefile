# Created by: Chris Hutchinson <portmaster@BSDforge.com>
# $FreeBSD$

PORTNAME=	xrdesktop2
PORTVERSION=	2.00
CATEGORIES=	net
MASTER_SITES=	http://BSDforge.com/projects/source/net/xrdesktop2/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	GTK2 frontend for Rdesktop

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	rdesktop:net/rdesktop \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2

CONFLICTS=	xrdesktop-1*

NO_BUILD=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix tar:xz
SHEBANG_FILES=	xrdesktop
DOCS=	Changelog INSTALL LICENSE README
PIXMAPS=	*.png

PLIST_FILES=	bin/xrdesktop share/doc/xrdesktop2/Changelog \
	share/doc/xrdesktop2/INSTALL share/doc/xrdesktop2/LICENSE \
	share/doc/xrdesktop2/README share/pixmaps/x-remote-desktop-256.png \
	share/pixmaps/x-remote-desktop-128.png \
	share/pixmaps/x-remote-desktop-48.png \
	share/applications/xrdesktop2.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xrdesktop ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PIXMAPS} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/xrdesktop2.desktop ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${WRKSRC}/${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
