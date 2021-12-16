# Created by: Dave Cottlehuber <dch@FreeBSD.org>

PORTNAME=	riemann
DISTVERSION=	0.3.8
PORTREVISION=	1
CATEGORIES=	net-mgmt java
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Monitors distributed systems

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE CDDL EPL GPLv2+ LGPL20+ MIT
LICENSE_COMB=	multi

USES=		tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8+

SUB_LIST=	JAVA_HOME=${JAVA_HOME}

PLIST_SUB=	JAVA_HOME=${JAVA_HOME}

USERS=		riemann
GROUPS=		riemann

USE_RC_SUBR=	riemann

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${ETCDIR}/conf.d \
		${STAGEDIR}/var/log/riemann
	${INSTALL_DATA} ${WRKSRC}/lib/riemann.jar \
		${STAGEDIR}${JAVAJARDIR}/riemann.jar
	${SED} -i -e "s:riemann.log:/var/log/riemann/riemann.log:g" \
		${WRKSRC}/etc/riemann.config
	${INSTALL_DATA} ${WRKSRC}/etc/riemann.config \
		${STAGEDIR}${ETCDIR}/riemann.config.sample

.include <bsd.port.mk>
