# Created by: Haowu Ge <ghw@7axu.com>
# $FreeBSD$

PORTNAME=	remotebox
PORTVERSION=	1.7
CATEGORIES=	net
MASTER_SITES=	http://remotebox.knobgoblin.org.uk/downloads/
DISTNAME=	RemoteBox-${PORTVERSION}

MAINTAINER=	ghw@7axu.com
COMMENT=	Open Source VirtualBox Client with Remote Management

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
		rdesktop:${PORTSDIR}/net/rdesktop

LICENSE_FILE_GPLv2=	${WRKSRC}/docs/COPYING

NO_BUILD=	yes
USE_BZIP2=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|docs/remotebox|share/doc/remotebox/remotebox|'  ${WRKSRC}/remotebox
	@${REINPLACE_CMD} -e 's|$$Bin/|${PREFIX}/|'	${WRKSRC}/remotebox
	@${REINPLACE_CMD} -e 's|$$Bin/|${PREFIX}/|' ${WRKSRC}/share/remotebox/rbox_gui_init.pl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/share/remotebox/*.pl ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/share/remotebox/*.pm ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/share/remotebox/remotebox.xml ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/icons/os
	${MKDIR} ${STAGEDIR}${DATADIR}/icons/gueststatus
	${INSTALL_DATA} ${WRKSRC}/share/remotebox/icons/*.png ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/share/remotebox/icons/os/*.png ${STAGEDIR}${DATADIR}/icons/os
	${INSTALL_DATA} ${WRKSRC}/share/remotebox/icons/gueststatus/*.png ${STAGEDIR}${DATADIR}/icons/gueststatus
	${INSTALL_DATA} ${WRKSRC}/share/remotebox/icons/remotebox.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/remotebox.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/changelog.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
