# ex:ts=8
# Ports collection makefile for:  clog
# Date created:			  Tue Nov 04, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	clog
PORTVERSION=	1.6
CATEGORIES=	net-mgmt security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Tcp connection logger daemon

WRKSRC=		${WRKDIR}/clog
ALL_TARGET=	freebsd
MAN8=		clog.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clog ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/clog.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
