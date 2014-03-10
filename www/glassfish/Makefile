# Created by: cjr@cruwe.de
# $FreeBSD$

PORTNAME=	glassfish
PORTVERSION=	3.1.2.2
CATEGORIES=	www java
MASTER_SITES=	http://download.java.net/glassfish/${PORTVERSION}/release/

MAINTAINER=	cjr@cruwe.de
COMMENT=	Reference implementation of the Java EE application server

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/glassfish3
DATADIR=	${PREFIX}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	GLASSFISHVERSION=${PORTVERSION} \
		PORTVERSION=${PORTVERSION}
SUB_LIST=	GLASSFISHVERSION=${PORTVERSION}

DOWNLOAD_URL=	http://download.java.net/glassfish/${PORTVERSION}/release/

USE_RC_SUBR=	glassfish
GLASSFISH_BIN_FILES=	appclient asadmin asupgrade capture-schema jspc package-appclient schemagen startserv stopserv wscompile wsdeploy wsgen wsimport xjc

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
