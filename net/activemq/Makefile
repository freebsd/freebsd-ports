PORTNAME=	activemq
PORTVERSION=	5.18.3
CATEGORIES=	net java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTVERSION}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	james@elstone.net
COMMENT=	Messaging and Integration Patterns provider
WWW=		https://activemq.apache.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe
CPE_VENDOR=	apache
USE_JAVA=	yes
JAVA_VERSION=	18
USE_RC_SUBR=	activemq

NO_ARCH=	yes
NO_BUILD=	yes

USERS=		activemq
GROUPS=		activemq

PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${REINPLACE_CMD} -i '' -e 's|$\{sys:activemq.data\}\/audit.log|\$\{sys:activemq.logs\}\/audit.log|g' ${WRKSRC}/conf/log4j2.properties
	@${REINPLACE_CMD} -i '' -e 's|$\{sys:activemq.data\}\/activemq.log|\$\{sys:activemq.logs\}\/activemq.log|g' ${WRKSRC}/conf/log4j2.properties
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	cd ${WRKSRC}/conf && for f in *; do \
		${INSTALL_DATA} ${WRKSRC}/conf/$$f ${STAGEDIR}${ETCDIR}/$$f.sample; \
	done
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/activemq* ${STAGEDIR}${DATADIR}/bin
	${RLN} ${STAGEDIR}${DATADIR}/bin/activemq ${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${DATADIR}/bin/activemq-diag ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/activemq.jar ${WRKSRC}/bin/wrapper.jar \
		${STAGEDIR}${DATADIR}/bin
	@${MKDIR} ${STAGEDIR}/var/db/activemq
	${RLN} ${STAGEDIR}/var/db/activemq ${STAGEDIR}${DATADIR}/data
	${RLN} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DATADIR}/conf
	cd ${WRKSRC} && ${COPYTREE_SHARE} "lib webapps webapps-demo" \
		${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NOTICE ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
	${RLN} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DATADIR}/docs

do-install-EXAMPLES-on:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${RLN} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DATADIR}/examples

.include <bsd.port.mk>
