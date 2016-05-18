# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ptpd
DISTVERSION=	2.3.1
CATEGORIES=	net
MASTER_SITES=	SF
PKGNAMESUFFIX=	2

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Implementation of the precision time protocol IEEE 1588-2008

LICENSE=	BSD2CLAUSE

CONFLICTS=	ptpd2-devel.*

ETCDIR=	${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool

PORTDOCS=	*

USE_RC_SUBR=	ptpd2

OPTIONS_DEFINE=	DOCS SNMP
OPTIONS_DEFAULT=SNMP

SNMP_CONFIGURE_ENABLE=	snmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${CP} ${FILESDIR}/*.sample ${STAGEDIR}${ETCDIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/ptpd-${DISTVERSION}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
