PORTNAME=	activemq
DISTVERSION=	6.2.0
CATEGORIES=	net java
MASTER_SITES=	APACHE/${PORTNAME}/${DISTVERSION}
DISTNAME=	apache-${PORTNAME}-${DISTVERSION}-bin

MAINTAINER=	james@elstone.net
COMMENT=	Messaging and Integration Patterns provider
WWW=		https://activemq.apache.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe java
CPE_VENDOR=	apache
JAVA_VERSION=	21 17
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/apache-${PORTNAME}-${DISTVERSION}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${REINPLACE_CMD} -i '' -e 's|$${sys:activemq.data}/audit.log|$${sys:activemq.logs}/audit.log|g; \
			s|$${sys:activemq.data}/activemq.log|$${sys:activemq.logs}/activemq.log|g' \
		${WRKSRC}/conf/log4j2.properties
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		 ${STAGEDIR}${DATADIR}/bin \
		 ${STAGEDIR}/var/db/${PORTNAME}
	cd ${WRKSRC}/conf && for f in *; do \
		${INSTALL_DATA} ${WRKSRC}/conf/$$f ${STAGEDIR}${ETCDIR}/$$f.sample; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/bin/activemq* ${STAGEDIR}${DATADIR}/bin
	${RLN} ${STAGEDIR}${DATADIR}/bin/activemq ${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${DATADIR}/bin/activemq-diag ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/activemq.jar ${WRKSRC}/bin/wrapper.jar \
		${STAGEDIR}${DATADIR}/bin
	${RLN} ${STAGEDIR}/var/db/activemq ${STAGEDIR}${DATADIR}/data
	${RLN} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DATADIR}/conf
	cd ${WRKSRC} && ${COPYTREE_SHARE} "lib webapps webapps-demo" ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NOTICE ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
	${RLN} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DATADIR}/docs

do-install-EXAMPLES-on:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${RLN} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DATADIR}/examples

.include <bsd.port.mk>
