# New ports collection makefile for:	tkxanim
# Date created:				24 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	tkxanim
PORTVERSION=	0.43
CATEGORIES=	multimedia tk82
MASTER_SITES=	http://members.yourlink.net/aaron/software/linux/

MAINTAINER=	jedgar@fxp.org
COMMENT=	Tcl/Tk frontend to xanim

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82 \
		xanim:${PORTSDIR}/multimedia/xanim

WRKSRC=		${WRKDIR}/Tkxanim

do-build:
		@${MV} ${WRKSRC}/tkxanim ${WRKSRC}/tkxanim.orig
		@${SED} -e 's|CHANGEME|${PREFIX}|' \
		    < ${WRKSRC}/tkxanim.orig > ${WRKSRC}/tkxanim

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/tkxanim ${PREFIX}/bin
		-${MKDIR} ${PREFIX}/share/icons
		${INSTALL_DATA} ${WRKSRC}/tkxanim.gif ${PREFIX}/share/icons

.include <bsd.port.mk>
