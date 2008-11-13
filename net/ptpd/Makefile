# New ports collection makefile for: ptpd
# Date created:		4 June 2008
# Whom:			George V. Neville-Neil <gnn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ptpd
DISTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	An implementation of the precision time protocol IEEE 1588

WRKSRC=		${WRKDIR}/ptpd-${DISTVERSION}/src

PLIST_FILES=	sbin/ptpd

USE_RC_SUBR=	ptpd

MAN8=		ptpd.8

do-install::
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
