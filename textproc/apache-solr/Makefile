# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	apache-solr
PORTVERSION=	8.5.0
CATEGORIES=	textproc java
MASTER_SITES=	APACHE/lucene/solr/${PORTVERSION}
DISTNAME=	solr-${PORTVERSION}

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	High performance search server built using Lucene Java

LICENSE=	APACHE20

RUN_DEPENDS=	bash:shells/bash

USES=		cpe tar:tgz
USE_JAVA=	yes
JAVA_VERSION=	11+
JAVA_RUN=	yes
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
SUB_FILES=	pkg-message
USE_RC_SUBR=	solr
USERS=		solr
GROUPS=		${USERS}

CPE_PRODUCT=	solr
CPE_VENDOR=	apache

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${CPE_PRODUCT}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/solr ${STAGEDIR}${PREFIX}/${CPE_PRODUCT}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/solr.in.sh ${STAGEDIR}${PREFIX}/etc/solr.in.sh.sample
	${ECHO} 'SOLR_HOME="/var/db/solr"' >> ${STAGEDIR}${PREFIX}/etc/solr.in.sh.sample
	${ECHO} '# LOG4J_PROPS="/var/db/solr/log4j2.xml"' >> ${STAGEDIR}${PREFIX}/etc/solr.in.sh.sample
	${ECHO} 'SOLR_LOGS_DIR="/var/log/solr"' >> ${STAGEDIR}${PREFIX}/etc/solr.in.sh.sample
	${ECHO} 'SOLR_PORT="8983"' >> ${STAGEDIR}${PREFIX}/etc/solr.in.sh.sample
	${ECHO} 'SOLR_PID_DIR="/var/db/solr"' >> ${STAGEDIR}${PREFIX}/etc/solr.in.sh.sample
	${ECHO} 'SOLR_OPTS="$$SOLR_OPTS -Djetty.host=localhost"' >> ${STAGEDIR}${PREFIX}/etc/solr.in.sh.sample

	${MKDIR} ${STAGEDIR}/var/db/solr
	${MKDIR} ${STAGEDIR}/var/log/solr
	${INSTALL_DATA} ${WRKSRC}/server/solr/solr.xml ${STAGEDIR}/var/db/solr/solr.xml.sample

.include <bsd.port.mk>
