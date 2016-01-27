# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jvmtop
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	sysutils java

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Lightweight console application to monitor running jvms

LICENSE=	GPLv2

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		bin/${PORTNAME}
SUB_LIST=	JAVA_HOME=${JAVA_HOME}
SUB_FILES=	${PORTNAME}.sh

GH_ACCOUNT=	patric-r
GH_TAG=		3d6978c
USE_GITHUB=	YES

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
