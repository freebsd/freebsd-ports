# Created by: cjr@cruwe.de 
# $FreeBSD$

PORTNAME=	glassfish
PORTVERSION=	5.1.0
CATEGORIES=	www java
MASTER_SITES=	ECLIPSE/glassfish
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	5

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Eclipse Jakarta EE Platform

LICENSE=	EPL

USES=		zip
USE_JAVA=	yes

JAVA_VERSION=	11+
NO_BUILD=	yes

CONFLICTS_INSTALL=	glassfish

WRKSRC=		${WRKDIR}/glassfish5
DATADIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}

# Since we USE_JAVA, we propagate the received JAVA_HOME variable to the
# template files, since it is used by the rc script.
SUB_LIST=	GLASSFISHVERSION=${PORTVERSION} \
		JAVA_HOME=${JAVA_HOME}

USE_RC_SUBR=	glassfish
GLASSFISH_BIN_FILES=	appclient appclient.js asadmin capture-schema capture-schema.1m jspc package-appclient schemagen startserv stopserv wscompile wsdeploy wsgen wsimport xjc

.include <bsd.port.pre.mk>

do-install:
	@${FIND} ${WRKSRC} -name '*.bat' -delete
	@${FIND} ${WRKSRC} -name '*.exe' -delete
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/bin/*
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/mq/bin/*
.for x in ${GLASSFISH_BIN_FILES}
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/glassfish/bin/${x}
.endfor

.include <bsd.port.post.mk>
