PORTNAME=	glassfish
DISTVERSION=	4.1.2
CATEGORIES=	www java
MASTER_SITES=	https://download.java.net/${PORTNAME}/${DISTVERSION}/release/ \
		https://download.oracle.com/${PORTNAME}/${DISTVERSION}/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reference implementation of the Java EE application server
WWW=		https://javaee.github.io/glassfish/

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/glassfish/legal/LICENSE.txt

DEPRECATED=	Very old version reached EoL, use www/glassfish 7.x instead
EXPIRATION_DATE=	2026-03-31

USES=		cpe java zip
CPE_VENDOR=	oracle
USE_RC_SUBR=	${PORTNAME}

CONFLICTS_INSTALL=	${PORTNAME}

DATADIR=	${PREFIX}/${PORTNAME}-${DISTVERSION}
EXTRACT_BEFORE_ARGS=	-qo -x '*.bat' -x '*.exe'

NO_ARCH=	yes
NO_BUILD=	yes

# Since we USES=java, we propagate the received JAVA_HOME variable to the
# template files, since it is used by the rc script.
SUB_LIST=	GLASSFISHVERSION=${DISTVERSION} \
		JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/${PORTNAME}${DISTVERSION:R:R}

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${FIND} ${STAGEDIR}${DATADIR}/glassfish/domains -path "*/config/*" -type f -exec ${MV} {} {}.sample \;
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/bin/* \
		${STAGEDIR}${DATADIR}/mq/bin/* \
		${STAGEDIR}${DATADIR}/glassfish/bin/*

.include <bsd.port.mk>
