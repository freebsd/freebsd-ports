# New ports collection makefile for:    pib
# Version required:     1.1
# Date created:         30 December 1996
# Whom:                 Mike Smith <msmith@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	pib-1.1
CATEGORIES=	sysutils tk82
MASTER_SITES=	http://www.freebsd.org/~msmith/pib/

MAINTAINER=	msmith@freebsd.org

BUILD_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82
RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

do-install:
	${MKDIR} ${PREFIX}/lib/pib
	${INSTALL_SCRIPT} ${WRKSRC}/*.tcl ${PREFIX}/lib/pib
	${INSTALL_DATA} ${WRKSRC}/libTkSteal.so.2* ${PREFIX}/lib/pib
	${LN} -fs ${PREFIX}/lib/pib/pib.tcl ${PREFIX}/bin/pib

.include <bsd.port.mk>
