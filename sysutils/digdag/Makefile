# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	digdag
DISTVERSION=	0.9.31
CATEGORIES=	sysutils java
MASTER_SITES=	https://dl.bintray.com/digdag/maven/
EXTRACT_SUFX=	.jar

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Workload Automation System

LICENSE=	APACHE20

USE_JAVA=	yes

JAVA_RUN=	yes
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.8+

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_SUB=	VERSION=${DISTVERSION}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${PRINTF} "#!/bin/sh\nexec \"${JAVA}\" -jar \
		\"${JAVAJARDIR}/${PORTNAME}/${PORTNAME}-${PORTVERSION}.jar\" \"\$$@\"\n" \
		> ${WRKSRC}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

cklatest:
	@${ECHO} "Port: ${DISTVERSION}"
	@${ECHO} -n "Upstream: "
	@curl -s -I https://dl.digdag.io/digdag-latest | \
		${SED} -n 's|.*digdag-\([0-9.]*\).jar|\1|p'

.include <bsd.port.mk>
