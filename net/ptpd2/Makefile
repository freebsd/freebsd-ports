# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ptpd
DISTVERSION=	2.3.0
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX=	2

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Implementation of the precision time protocol IEEE 1588-2008

LICENSE=	BSD2CLAUSE

CONFLICTS=	ptpd2-devel.*

LIB_DEPENDS+=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp

ETCDIR=	${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}

USES=	gmake
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:env aclocal:env automake:env libtool

PORTDOCS=	*

USE_RC_SUBR=	ptpd2

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

run-autotools:	run-autotools-autoreconf

run-autotools-autoreconf:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -i

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/ptpd-${DISTVERSION}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${CP} ${FILESDIR}/*.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
