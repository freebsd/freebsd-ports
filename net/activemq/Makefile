# $FreeBSD$

PORTNAME=	activemq
PORTVERSION=	5.15.13
CATEGORIES=	net java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTVERSION}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Messaging and Integration Patterns provider

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe
CPE_VENDOR=	apache
USE_JAVA=	yes
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
	${RM} ${WRKSRC}/conf/log4j.properties.orig
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
