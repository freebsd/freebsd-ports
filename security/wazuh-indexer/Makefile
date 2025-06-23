PORTNAME=	wazuh
PORTVERSION=	4.12.0
CATEGORIES=	security
MASTER_SITES=	LOCAL/acm/${PORTNAME}/
PKGNAMESUFFIX=	-indexer
DISTFILES=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}.yml
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A highly scalable, full-text search and analytics engine
WWW=		https://wazuh.com/

LICENSE=	GPLv2

DEPRECATED=	Depends on expiring textproc/opensearch-dashboards219
EXPIRATION_DATE=2025-09-01

RUN_DEPENDS=	${LOCALBASE}/lib/opensearch/bin/opensearch:textproc/opensearch219

NO_BUILD=	yes

PLIST_FILES=	etc/wazuh-indexer/wazuh-indexer.yml

SUB_FILES=	pkg-message

ETCDIR=		${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${_DISTDIR}/${PORTNAME}-${PORTVERSION}-indexer.yml ${WRKSRC}/wazuh-indexer.yml

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}
	${INSTALL_DATA} ${WRKSRC}/wazuh-indexer.yml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}/wazuh-indexer.yml
	
.include <bsd.port.mk>
