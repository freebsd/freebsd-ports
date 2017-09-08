# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	riemann
PORTVERSION=	0.2.14
CATEGORIES=	net-mgmt java
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	dch@skunkwerks.at
COMMENT=	Monitors distributed systems

LICENSE=	EPL

USES=		tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8+

SUB_LIST=	JAVA_HOME=${JAVA_HOME}

PLIST_SUB=	JAVA_HOME=${JAVA_HOME}

USERS=	riemann
GROUPS=	riemann

USE_RC_SUBR=	riemann

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${ETCDIR}/conf.d \
		${STAGEDIR}/var/log/riemann
	${INSTALL_DATA} ${WRKSRC}/lib/riemann.jar \
		${STAGEDIR}${JAVAJARDIR}/riemann.jar
	${SED} -i -e "s:riemann.log:/var/log/riemann.log:g" \
		${WRKSRC}/etc/riemann.config
	${INSTALL_DATA} ${WRKSRC}/etc/riemann.config \
		${STAGEDIR}${ETCDIR}/riemann.config.sample

.include <bsd.port.mk>
