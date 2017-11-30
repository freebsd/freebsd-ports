# Created by: Anish Mistry (with help from mean)
# $FreeBSD$
# assuming freebsd always has 16 byte aligned malloc as macos does. is this true?
# nls files not getting installed with nls=on. are they getting built?
# sync port options with current software options

PORTNAME=	avidemux
PORTVERSION=	${AVIDEMUX_VERSION}
PORTREVISION=	6
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

CMAKE_SOURCE_PATH=	${WRKSRC}/avidemux_core

post-configure: post-configure-common

post-install:
.if ${PORT_OPTIONS:MGTK3} || ${PORT_OPTIONS:MQT4}
	@${MKDIR} "${STAGEDIR}${DATADIR}"
	${INSTALL_DATA} "${WRKSRC}/avidemux_icon.png" "${STAGEDIR}${DATADIR}/${PORTNAME}.png"
.if ${PORT_OPTIONS:MGTK3}
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
.endif

.include <bsd.port.post.mk>
