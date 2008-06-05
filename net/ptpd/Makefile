# New ports collection makefile for: ptpd
# Date created:		4 June 2008
# Whom:			George V. Neville-Neil <gnn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ptpd
DISTVERSION=	1rc1
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ptpd_${DISTVERSION}

MAINTAINER=	gnn@freebsd.org
COMMENT=	An implementation of the precision time protocol IEEE 1588

WRKSRC=		${WRKDIR}/ptpd/src

PLIST_FILES=	bin/ptpd

USE_RC_SUBR=	ptp

MAN8=		ptpd.8

do-install::
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
