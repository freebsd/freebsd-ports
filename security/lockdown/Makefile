# New ports collection makefile for: lockdown
# Date created:		2004-02-11
# Whom:			Daniel Blankensteiner <db@TruNet.dk>
#
# $FreeBSD$
#

PORTNAME=	lockdown
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://lockdown.trunet.dk/ \
		http://lockdown.loproc.dk/

MAINTAINER=	db@TruNet.dk
COMMENT=	Hardening system for FreeBSD

MAN1=		lockdown.1

WRKSRC=		${WRKDIR}/lockdown

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lockdown ${PREFIX}/bin/lockdown
	${INSTALL_MAN} ${WRKSRC}/lockdown.1 ${PREFIX}/man/man1/lockdown.1
	${INSTALL_DATA} ${WRKSRC}/lockdown.conf.sample ${PREFIX}/etc/lockdown.conf.sample

.include <bsd.port.mk>
