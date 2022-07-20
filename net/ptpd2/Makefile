PORTNAME=	ptpd
DISTVERSION=	2.3.1
CATEGORIES=	net
PKGNAMESUFFIX=	2

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Implementation of the precision time protocol IEEE 1588-2008

LICENSE=	BSD2CLAUSE

CONFLICTS=	ptpd2-devel.*

ETCDIR=	${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_TAGNAME=	d27a6e0
USE_RC_SUBR=	ptpd2

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS SNMP
OPTIONS_DEFAULT=SNMP

SNMP_CONFIGURE_ENABLE=	snmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${CP} ${FILESDIR}/*.sample ${STAGEDIR}${ETCDIR}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
