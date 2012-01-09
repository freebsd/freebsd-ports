# New ports collection makefile for:	activemq
# Date created:		2010-02-07
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	activemq
PORTVERSION=	5.5.0
CATEGORIES=	net java
MASTER_SITES=	http://www.sai.msu.su/apache/${MASTER_SITE_SUBDIR}/ \
		${MASTER_SITE_APACHE}/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=${PORTNAME}/apache-${PORTNAME}/${PORTVERSION}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Messaging and Integration Patterns provider

NO_BUILD=	yes

USE_JAVA=	yes
LICENSE=	AL2
JAVA_VERSION=	1.5+
MQDATA=		${PREFIX}/lib/${PORTNAME}
MQDB=		${PREFIX}/${PORTNAME}
DATADIR=	${MQDATA}
MQUSER=		activemq
MQGROUP=	${MQUSER}
USERS=		${MQUSER}
GROUPS=		${MQGROUP}

ALL_TARGET=	${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

PORTDOCS=	LICENSE NOTICE README.txt WebConsole-README.txt user-guide.html
ETC_FILES=	activemq-command.xml \
		activemq-demo.xml \
		activemq-dynamic-network-broker1.xml \
		activemq-dynamic-network-broker2.xml \
		activemq-jdbc.xml \
		activemq-scalability.xml \
		activemq-security.xml \
		activemq-specjms.xml \
		activemq-static-network-broker1.xml \
		activemq-static-network-broker2.xml \
		activemq-stomp.xml \
		activemq-throughput.xml \
		activemq.xml \
		broker-localhost.cert \
		broker.ks \
		broker.ts \
		camel.xml \
		client.ks \
		client.ts \
		credentials-enc.properties \
		credentials.properties \
		jetty-realm.properties \
		jetty.xml \
		jmx.access \
		jmx.password \
		log4j.properties \
		logging.properties

WRKSRC=		${WRKDIR}/apache-${PORTNAME}-${PORTVERSION}
SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	ETC_FILES="${ETC_FILES}"

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${DOCSDIR}/
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

	@${MKDIR} ${MQDATA} ${MQDB} ${MQDATA}/bin ${ETCDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} example ${EXAMPLESDIR}/

.for f in ${ETC_FILES}
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${ETCDIR}/${f}.sample
.endfor

.for f in ${PORTNAME} ${PORTNAME}-admin
	@cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} ${f} ${MQDATA}/bin
.endfor
.for f in run.jar wrapper.jar
	@cd ${WRKSRC}/bin && ${INSTALL_DATA} ${f} ${MQDATA}/bin
.endfor
.for f in webapps lib
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${MQDATA}
.endfor

	@${LN} -sf ${MQDB} ${MQDATA}/data
	@${LN} -sf ${ETCDIR} ${MQDATA}/conf
	@${LN} -sf ${EXAMPLESDIR}/example ${MQDATA}/example
	@${CHOWN} -Rh ${MQUSER}:${MQGROUP} ${MQDB} ${ETCDIR} ${EXAMPLES} ${MQDATA}

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
