# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jvmtop
PORTVERSION=	0.8.0
CATEGORIES=	sysutils java
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Lightweight console application to monitor running jvms

LICENSE=	GPLv3

USE_JAVA=	yes
JAVA_VERSION=	1.6+

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		bin/${PORTNAME}
SUB_LIST=	JAVA_HOME=${JAVA_HOME}
SUB_FILES=	${PORTNAME}.sh
NO_BUILD=	yes

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
