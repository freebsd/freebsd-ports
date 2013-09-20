# Created by: George V. Neville-Neil <gnn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ptpd
DISTVERSION=	1.1.0
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	An implementation of the precision time protocol IEEE 1588

LICENSE=	BSD
LATEST_LINK=	ptpd1

WRKSRC=		${WRKDIR}/ptpd-${DISTVERSION}/src
CFLAGS+=	-DBSD_INTERFACE_FUNCTIONS

PLIST_FILES=	sbin/ptpd
PORTDOCS=	*

USE_RC_SUBR=	ptpd

MAN8=		ptpd.8

NO_STAGE=	yes
do-install::
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/ptpd-${DISTVERSION}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
