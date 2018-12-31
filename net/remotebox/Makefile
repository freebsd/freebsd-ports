# Created by: Haowu Ge <ghw@7axu.com>
# $FreeBSD$

PORTNAME=	remotebox
DISTVERSION=	2.5
CATEGORIES=	net
MASTER_SITES=	http://remotebox.knobgoblin.org.uk/downloads/
DISTNAME=	RemoteBox-${DISTVERSION}

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Open Source VirtualBox Client with Remote Management

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING

RUN_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		p5-SOAP-Lite>=0:net/p5-SOAP-Lite

USES=		shebangfix tar:bzip2
SHEBANG_FILES=	remotebox
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS KRDC
OPTIONS_DEFAULT=	FREERDP TIGERVNC
OPTIONS_MULTI=		VIEWER
OPTIONS_MULTI_VIEWER=	FREERDP RDESKTOP TIGERVNC VINAGRE

FREERDP_DESC=		RDP client (fork of rdesktop with more features)
KRDC_DESC=		RDP/VNC client for KDE5
RDESKTOP_DESC=		RDP client (less features than freerdp)
TIGERVNC_DESC=		VNC client (desktop neutral)
VINAGRE_DESC=		VNC client for GNOME

FREERDP_RUN_DEPENDS=	xfreerdp:net/freerdp
KRDC_RUN_DEPENDS=	krdc:net/krdc
RDESKTOP_RUN_DEPENDS=	rdesktop:net/rdesktop
TIGERVNC_RUN_DEPENDS=	vncviewer:net/tigervnc
VINAGRE_RUN_DEPENDS=	vinagre:net/vinagre

post-patch:
	@${REINPLACE_CMD} -e 's|$$Bin/share/remotebox|${DATADIR}|; \
		s|$$Bin/docs|${DOCSDIR}|' \
	       	${WRKSRC}/remotebox

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/share/remotebox/*.pl ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/share/remotebox/*.pm ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/share/remotebox/remotebox.xml \
	       ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons/os
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons/gueststatus
	${INSTALL_DATA} ${WRKSRC}/share/remotebox/icons/*.png \
	       ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/share/remotebox/icons/os/*.png \
	       ${STAGEDIR}${DATADIR}/icons/os
	${INSTALL_DATA} ${WRKSRC}/share/remotebox/icons/gueststatus/*.png \
	       ${STAGEDIR}${DATADIR}/icons/gueststatus
	${INSTALL_DATA} ${WRKSRC}/share/remotebox/icons/remotebox.png \
	       ${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/remotebox.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/changelog.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
