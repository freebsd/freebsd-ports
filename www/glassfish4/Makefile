# Created by: cjr@cruwe.de
# $FreeBSD$

PORTNAME=	glassfish
PORTVERSION=	4.1
CATEGORIES=	www java
MASTER_SITES=	http://dlc.sun.com.edgesuite.net/glassfish/${PORTVERSION}/release/

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Reference implementation of the Java EE application server

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.7+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/glassfish4
DATADIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}

# Since we USE_JAVA, we propagate the received JAVA_HOME variable to the
# template files, since it is used by the rc script.
SUB_LIST=	GLASSFISHVERSION=${PORTVERSION} \
		JAVA_HOME=${JAVA_HOME}

DOWNLOAD_URL=	http://dlc.sun.com.edgesuite.net/glassfish/${PORTVERSION}/release/

USE_RC_SUBR=	glassfish
GLASSFISH_BIN_FILES=	appclient asadmin capture-schema jspc package-appclient schemagen startserv stopserv wscompile wsdeploy wsgen wsimport xjc

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
