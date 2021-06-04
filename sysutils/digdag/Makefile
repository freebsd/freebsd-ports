# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	digdag
DISTVERSION=	0.10.1
CATEGORIES=	sysutils java
MASTER_SITES=	https://github.com/treasure-data/digdag/releases/download/v${DISTVERSION}/ \
		LOCAL/ehaupt
EXTRACT_SUFX=	.jar

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Workload Automation System

LICENSE=	APACHE20

USE_JAVA=	yes
USE_RC_SUBR=	${PORTNAME}

JAVA_RUN=	yes
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.8+

NO_BUILD=	yes
NO_ARCH=	yes

USERS=		digdag

SUB_LIST=	PORTNAME=${PORTNAME} USERS=${USERS} JAVA=${JAVA}
PLIST_SUB=	VERSION=${DISTVERSION} USERS=${USERS}

VARLOG=		/var/log/${PORTNAME}
VARRUN=		/var/run/${PORTNAME}

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
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample \
		${STAGEDIR}${PREFIX}/etc

	@${MKDIR} ${STAGEDIR}${VARLOG}
	@${MKDIR} ${STAGEDIR}${VARRUN}

cklatest:
	@${ECHO} "Port: ${DISTVERSION}"
	@${ECHO} -n "Upstream: "
	@curl -s -I https://dl.digdag.io/digdag-latest | \
		${SED} -n 's|.*digdag-\([0-9.]*\).jar|\1|p'

.include <bsd.port.mk>
