# Ports collection makefile for:	mgeupsd
# Date created:				12 Aug 1999
# Whom:                                 Andreas Dobloug <andreasd@@ifi.uio.no>
#
# $FreeBSD$
#

PORTNAME=		mgeupsd
PORTVERSION=		0.3
PORTREVISION=	1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/ups

MAINTAINER=		ports@FreeBSD.org
COMMENT=	monitor a state of MGE Pulsar UPS connected to RS-232 port

USE_GMAKE=		YES
WRKSRC=			${WRKDIR}/MGE

post-install:
		${INSTALL_SCRIPT} ${FILESDIR}/mgeupsd.sh ${PREFIX}/etc/rc.d
		${INSTALL_SCRIPT} ${FILESDIR}/powerhandler ${PREFIX}/sbin
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
