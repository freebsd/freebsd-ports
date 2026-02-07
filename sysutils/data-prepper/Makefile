PORTNAME=	data-prepper
DISTVERSION=	2.12.0
DISTVERSIONSUFFIX=	-linux-x64
CATEGORIES=	sysutils java
MASTER_SITES=	https://artifacts.opensearch.org/${PORTNAME}/${DISTVERSION}/
DISTNAME=	opensearch-${PORTNAME}-jdk-${DISTVERSIONFULL}

MAINTAINER=	opensearch@FreeBSD.org
COMMENT=	Server-side data collector for OpenSearch
WWW=		https://opensearch.org

LICENSE=	APACHE20

RUN_DEPENDS=	bash>0:shells/bash

USES=		cpe shebangfix java
JAVA_VERSION=	17+
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	bin/data-prepper

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	data-prepper pkg-message
SUB_LIST=	SEARCHUSER=${SEARCHUSER} SEARCHGROUP=${SEARCHGROUP} JAVA_HOME=${JAVA_HOME}

BINS=		data-prepper
CONFIG_FILES=	data-prepper-config.yaml log4j2-rolling.properties

SEARCHUSER=	opensearch
SEARCHGROUP=	${SEARCHUSER}
USERS=		${SEARCHUSER}
GROUPS=		${SEARCHGROUP}

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for f in ${CONFIG_FILES}
	${INSTALL} ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
.for f in ${BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${DATADIR}/bin
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/)
	${MKDIR} ${STAGEDIR}${DATADIR}/lib
	${MKDIR} ${STAGEDIR}${DATADIR}/pipelines
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "lib pipelines" ${STAGEDIR}${DATADIR}/)
	${RLN} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DATADIR}/config

.include <bsd.port.mk>
