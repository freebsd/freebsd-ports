PORTNAME=	glassfish
DISTVERSION=	7.1.0
CATEGORIES=	www java
MASTER_SITES=	ECLIPSE/ee4j/${PORTNAME}
PKGNAMEPREFIX=	eclipse-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eclipse Jakarta EE Platform
WWW=		https://projects.eclipse.org/projects/ee4j.glassfish

LICENSE=	EPL

USES=		java zip
JAVA_VERSION=	17+
USE_RC_SUBR=	${PORTNAME}

CONFLICTS_INSTALL=	${PORTNAME}4

DATADIR=	${PREFIX}/${PORTNAME}-${DISTVERSION}
EXTRACT_BEFORE_ARGS=	-qo -x '*.bat' -x '*.exe'

NO_ARCH=	yes
NO_BUILD=	yes

# Since we USES=java, we propagate the received JAVA_HOME variable to the
# template files, since it is used by the rc script.
SUB_LIST=	GLASSFISHVERSION=${DISTVERSION} \
		JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/${PORTNAME}${DISTVERSION:R:R}

post-patch:
	${SED} -i '' 's|#!/bin/bash|#!/bin/sh|' \
		${bin/asadmin \
		bin/debug-asadmin \
		bin/startserv \
		bin/stopserv \
		glassfish/bin/appclient \
		glassfish/bin/asadmin \
		glassfish/bin/jspc \
		glassfish/bin/package-appclient \
		glassfish/bin/schemagen \
		glassfish/bin/startserv \
		glassfish/bin/stopserv \
		glassfish/bin/wsgen \
		glassfish/bin/wsimport \
		glassfish/bin/xjc:L:S|^|${WRKSRC}/|}

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${FIND} ${STAGEDIR}${DATADIR}/glassfish/domains -path "*/config/*" -type f -exec ${MV} {} {}.sample \;
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/bin/* \
		${STAGEDIR}${DATADIR}/mq/bin/* \
		${STAGEDIR}${DATADIR}/glassfish/bin/*

.include <bsd.port.mk>
