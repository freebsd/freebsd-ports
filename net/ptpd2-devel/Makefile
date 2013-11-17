# Created by: George V. Neville-Neil <gnn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ptpd
DISTVERSION=	2-RC-0
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/$(PORTNAME)/2-RC/
PKGNAMESUFFIX=	2-devel

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Release candidate for the precision time protocol IEEE 1588-2008

LICENSE=	BSD

WRKSRC=		${WRKDIR}/ptpd-${DISTVERSION}/src

CONFLICTS=	ptpd2-2.[0-9].*

PLIST_FILES=	sbin/ptpd2
PORTDOCS=	*

USE_RC_SUBR=	ptpd2

MAN8=		ptpd2.8

NO_STAGE=	yes
do-install::
	${INSTALL_PROGRAM} ${WRKSRC}/ptpd2 ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MANPREFIX}/man/man8/${MAN8}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/ptpd-${DISTVERSION}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
