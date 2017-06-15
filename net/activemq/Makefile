# $FreeBSD$

PORTNAME=	activemq
PORTVERSION=	5.14.1
CATEGORIES=	net java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTVERSION}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Messaging and Integration Patterns provider

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		cpe
CPE_VENDOR=	apache
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.7+
MQDATA=		${PREFIX}/lib/${PORTNAME}
MQDB?=		/var/db/activemq
DATADIR=	${MQDATA}
MQUSER?=	activemq
MQGROUP?=	${MQUSER}
USERS=		${MQUSER}
GROUPS=		${MQGROUP}
CAMELVERSION=	2.16.3
SPRINGVERSION=	4.1.9
JETTYVERSION=	9.2.13.v20150730
LVDBVERSION=	0.6
LVDBJNIVERSION=	1.8

ALL_TARGET=	${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

DOC_FILES=	LICENSE NOTICE README.txt
ETC_FILES=	activemq.xml \
		broker-localhost.cert \
		broker.ks \
		broker.ts \
		client.ks \
		client.ts \
		credentials-enc.properties \
		credentials.properties \
		groups.properties \
		jetty-realm.properties \
		jetty.xml \
		jmx.access \
		jmx.password \
		log4j.properties \
		logging.properties \
		login.config \
		users.properties
WRKSRC=		${WRKDIR}/apache-${PORTNAME}-${PORTVERSION}
SUB_LIST=	ETC_FILES="${ETC_FILES}" \
		MQUSER="${MQUSER}" \
		MQGROUP="${MQGROUP}" \
		MQDB="${MQDB}"
PLIST_SUB=	MQUSER="${MQUSER}" \
		MQGROUP="${MQGROUP}" \
		MQDB="${MQDB}" \
		PORTVERSION="${PORTVERSION}" \
		CAMELVERSION="${CAMELVERSION}" \
		SPRINGVERSION="${SPRINGVERSION}" \
		JETTYVERSION="${JETTYVERSION}" \
		LVDBVERSION="${LVDBVERSION}" \
		LVDBJNIVERSION="${LVDBJNIVERSION}"

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	 @${REINPLACE_CMD} -e 's|activemq.base}/data|activemq.logs}|g' ${WRKSRC}/conf/log4j.properties

do-install:
	@${MKDIR} ${STAGEDIR}${MQDATA} ${STAGEDIR}${MQDATA}/bin ${STAGEDIR}${ETCDIR}

.for f in ${ETC_FILES}
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

.for f in ${PORTNAME} ${PORTNAME}-diag
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${MQDATA}/bin
.endfor

	${INSTALL_DATA} ${WRKSRC}/bin/activemq.jar ${STAGEDIR}${MQDATA}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/wrapper.jar ${STAGEDIR}${MQDATA}/bin

.for f in webapps webapps-demo lib
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${MQDATA})
.endfor

	@${LN} -sf ${MQDB} ${STAGEDIR}${MQDATA}/data
	@${LN} -sf ${ETCDIR} ${STAGEDIR}${MQDATA}/conf

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/)
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
	@${LN} -sf ${DOCSDIR} ${STAGEDIR}${MQDATA}/docs

do-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	@${LN} -sf ${EXAMPLESDIR} ${STAGEDIR}${MQDATA}/examples

.include <bsd.port.mk>
