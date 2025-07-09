PORTNAME=	remotebox
DISTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://remotebox.knobgoblin.org.uk/downloads/
DISTNAME=	RemoteBox-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source VirtualBox Client with Remote Management
WWW=		https://remotebox.knobgoblin.org.uk/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING

RUN_DEPENDS=	p5-Gtk3>0:x11-toolkits/p5-Gtk3 \
		p5-SOAP-Lite>0:net/p5-SOAP-Lite

USES=		shebangfix tar:bzip2

SHEBANG_FILES=	remotebox
NO_ARCH=	yes
NO_BUILD=	yes

DESKTOP_ENTRIES=	"RemoteBox" "${COMMENT}" "${PORTNAME}" "${PORTNAME}" \
			"System;" false

OPTIONS_DEFINE=		KRDC
OPTIONS_DEFAULT=	FREERDP TIGERVNC
OPTIONS_MULTI=		VIEWER
OPTIONS_MULTI_VIEWER=	FREERDP RDESKTOP TIGERVNC VINAGRE

FREERDP_DESC=	RDP client (fork of rdesktop with more features)
KRDC_DESC=	RDP/VNC client for KDE
RDESKTOP_DESC=	RDP client (less features than FreeRDP)
TIGERVNC_DESC=	VNC client (desktop neutral)
VINAGRE_DESC=	VNC client for GNOME

FREERDP_RUN_DEPENDS=	xfreerdp:net/freerdp
KRDC_RUN_DEPENDS=	krdc:net/krdc
RDESKTOP_RUN_DEPENDS=	rdesktop:net/rdesktop
TIGERVNC_RUN_DEPENDS=	vncviewer:net/tigervnc-viewer
VINAGRE_RUN_DEPENDS=	vinagre:net/vinagre

post-patch:
	@${REINPLACE_CMD} -e 's|$$Bin/share/remotebox|${DATADIR}|' \
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

.include <bsd.port.mk>
