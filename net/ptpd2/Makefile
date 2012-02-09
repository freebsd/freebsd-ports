# New ports collection makefile for: ptpd2
# Date created:		16 November 2010
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ptpd
DISTVERSION=	2.2.0
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Implementation of the precision time protocol IEEE 1588-2008

LICENSE=	BSD

WRKSRC=		${WRKDIR}/ptpd-${DISTVERSION}/src

PLIST_FILES=	sbin/ptpd2
PORTDOCS=	*

USE_RC_SUBR=	ptpd2

MAN8=		ptpd2.8

do-install::
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}2 ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}2.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/ptpd-${DISTVERSION}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
