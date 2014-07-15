# Created by: George V. Neville-Neil <gnn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ptpd
DISTVERSION=	2-RC-0
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/$(PORTNAME)/2-RC/
PKGNAMESUFFIX=	2-devel

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Release candidate for the precision time protocol IEEE 1588-2008

LICENSE=	BSD2CLAUSE

WRKSRC=		${WRKDIR}/ptpd-${DISTVERSION}/src

CONFLICTS=	ptpd2-2.[0-9].*

PLIST_FILES=	sbin/ptpd2 man/man8/ptpd2.8.gz
PORTDOCS=	*

USE_RC_SUBR=	ptpd2

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install::
	${INSTALL_PROGRAM} ${WRKSRC}/ptpd2 ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ptpd2.8 ${STAGEDIR}${MANPREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/ptpd-${DISTVERSION}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
