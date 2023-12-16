PORTNAME=	wazuh
PORTVERSION=	4.7.0
CATEGORIES=	security
MASTER_SITES=	LOCAL/acm/${PORTNAME}/
PKGNAMESUFFIX=	-indexer
DISTFILES=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}.yml
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A highly scalable, full-text search and analytics engine
WWW=		https://wazuh.com/

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/lib/opensearch/bin/opensearch:textproc/opensearch210

NO_BUILD=	yes

PLIST_FILES=	etc/wazuh-indexer/wazuh-indexer.yml

SUB_FILES=	pkg-message

ETCDIR=		${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${_DISTDIR}/${PORTNAME}-${PORTVERSION}-indexer.yml ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}-${PORTVERSION}-indexer
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}-indexer.yml \
		${STAGEDIR}${PREFIX}/etc/wazuh-indexer/wazuh-indexer.yml
	
.include <bsd.port.mk>
