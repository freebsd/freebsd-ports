# New ports collection makefile for:	pidgin-facebookchat
# Date created:		2008-07-27
# Whom:			ports@c0decafe.net <ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	pidgin-facebookchat
PORTVERSION=	1.50
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PROJECTHOST}-source-${PORTVERSION}

MAINTAINER=	ports@c0decafe.net
COMMENT=	Facebook Chat for Pidgin

BUILD_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

PROJECTHOST=	${PORTNAME}
WRKSRC=		${WRKDIR}/pidgin-facebookchat
USE_BZIP2=	yes

PIXMAPS_DIR=	${PREFIX}/share/pixmaps/pidgin/protocols

do-patch:
	${REINPLACE_CMD} -e "s#i686-pc-freebsd6.0-gcc#${CC}#; s#/usr/local/#${LOCALBASE}/#g" \
		${WRKSRC}/Makefile

do-build:
	${MAKE} -C ${WRKSRC} libfacebookbsd60.so

do-install:
	${MKDIR} ${PREFIX}/lib/purple-2/ \
		 ${PIXMAPS_DIR}/16 ${PIXMAPS_DIR}/22 ${PIXMAPS_DIR}/48
	${INSTALL_DATA} ${WRKSRC}/libfacebook.so ${PREFIX}/lib/purple-2/
	${INSTALL_DATA} ${WRKSRC}/facebook16.png ${PIXMAPS_DIR}/16/facebook.png
	${INSTALL_DATA} ${WRKSRC}/facebook22.png ${PIXMAPS_DIR}/22/facebook.png
	${INSTALL_DATA} ${WRKSRC}/facebook48.png ${PIXMAPS_DIR}/48/facebook.png

.include <bsd.port.mk>
