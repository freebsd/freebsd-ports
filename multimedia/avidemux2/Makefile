# Created by: Anish Mistry (with help from mean)
# $FreeBSD$

PORTNAME=	avidemux2
PORTVERSION=	${AVIDEMUX2_VERSION}
PORTREVISION=	8
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Simple GUI based video editor

.include "${.CURDIR}/Makefile.common"

.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MQT4}
PLIST_FILES+=	${DATADIR}/${PORTNAME}.png
.endif

.if ${PORT_OPTIONS:MGTK2}
PLIST_FILES+=	${DESKTOPDIR}/${PORTNAME}.desktop
.endif
.if ${PORT_OPTIONS:MQT4}
PLIST_FILES+=	${DESKTOPDIR}/${PORTNAME}_qt4.desktop
.endif

post-configure: post-configure-common

post-install:
.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MQT4}
	@${MKDIR} "${STAGEDIR}${DATADIR}"
	${INSTALL_DATA} "${WRKSRC}/avidemux_icon.png" "${STAGEDIR}${DATADIR}/${PORTNAME}.png"
	@${MKDIR} "${STAGEDIR}${DESKTOPDIR}"
.if ${PORT_OPTIONS:MGTK2}
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%DATADIR%%|${DATADIR}|g" \
	    -e "s|%%NAME%%|${PORTNAME}|g" -e "s|%%API%%|gtk|g" \
	    < ${FILESDIR}/avidemux2.desktop.in > ${WRKDIR}/${PORTNAME}.desktop
	${INSTALL_DATA} "${WRKDIR}/${PORTNAME}.desktop" "${STAGEDIR}${DESKTOPDIR}"
.endif
.if ${PORT_OPTIONS:MQT4}
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%DATADIR%%|${DATADIR}|g" \
	    -e "s|%%NAME%%|${PORTNAME}|g" -e "s|%%API%%|qt4|g" \
	    < ${FILESDIR}/avidemux2.desktop.in > ${WRKDIR}/${PORTNAME}_qt4.desktop
	${INSTALL_DATA} "${WRKDIR}/${PORTNAME}_qt4.desktop" "${STAGEDIR}${DESKTOPDIR}"
.endif
	@${ECHO_CMD} "@unexec ${RMDIR} ${DESKTOPDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec %D/bin/update-desktop-database 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec %D/bin/update-desktop-database 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
