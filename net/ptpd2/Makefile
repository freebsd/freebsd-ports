# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ptpd
DISTVERSION=	2.3.1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
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
OPTIONS_DEFAULT=DOCS SNMP

SNMP_CONFIGURE_ENABLE=	snmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/ptpd-${DISTVERSION}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${CP} ${FILESDIR}/*.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
