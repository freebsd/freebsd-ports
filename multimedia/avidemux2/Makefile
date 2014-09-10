# Created by: Anish Mistry (with help from mean)
# $FreeBSD$

PORTNAME=	avidemux2
PORTVERSION=	${AVIDEMUX2_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Simple GUI based video editor

.include "${.CURDIR}/Makefile.common"

post-configure: post-configure-common

post-install:
.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MQT4}
	@${MKDIR} "${STAGEDIR}${DATADIR}"
	${INSTALL_DATA} "${WRKSRC}/avidemux_icon.png" "${STAGEDIR}${DATADIR}/${PORTNAME}.png"
	@${ECHO_CMD} "${DATADIR_REL}/${PORTNAME}.png" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/${DATADIR_REL} 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${MKDIR} "${STAGEDIR}${DESKTOPDIR}"
	@${ECHO_CMD} "@cwd ${DESKTOPDIR}" >> ${TMPPLIST}
.if ${PORT_OPTIONS:MGTK2}
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%DATADIR%%|${DATADIR}|g" \
	    -e "s|%%NAME%%|${PORTNAME}|g" -e "s|%%API%%|gtk|g" \
	    < ${FILESDIR}/avidemux2.desktop.in > ${WRKDIR}/${PORTNAME}.desktop
	${INSTALL_DATA} "${WRKDIR}/${PORTNAME}.desktop" "${STAGEDIR}${DESKTOPDIR}"
	@${ECHO_CMD} "${PORTNAME}.desktop" >> ${TMPPLIST}
.endif
.if ${PORT_OPTIONS:MQT4}
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%DATADIR%%|${DATADIR}|g" \
	    -e "s|%%NAME%%|${PORTNAME}|g" -e "s|%%API%%|qt4|g" \
	    < ${FILESDIR}/avidemux2.desktop.in > ${WRKDIR}/${PORTNAME}_qt4.desktop
	${INSTALL_DATA} "${WRKDIR}/${PORTNAME}_qt4.desktop" "${STAGEDIR}${DESKTOPDIR}"
	@${ECHO_CMD} "${PORTNAME}_qt4.desktop" >> ${TMPPLIST}
.endif
	@${ECHO_CMD} "@cwd ${PREFIX}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} ${DESKTOPDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec %D/bin/update-desktop-database 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec %D/bin/update-desktop-database 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
