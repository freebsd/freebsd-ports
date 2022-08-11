PORTNAME=	digdag
DISTVERSION=	0.10.4
PORTREVISION=	1
CATEGORIES=	sysutils java
MASTER_SITES=	https://github.com/treasure-data/digdag/releases/download/v${DISTVERSION}/ \
		LOCAL/ehaupt
EXTRACT_SUFX=	.jar

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Workload Automation System

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_LIST=	JAVA=${JAVA} \
		PORTNAME=${PORTNAME} \
		USERS=${USERS}
USERS=		digdag
PLIST_SUB=	USERS=${USERS} \
		VERSION=${DISTVERSION}

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

	@${MKDIR} ${STAGEDIR}${VARRUN}

cklatest:
	@${ECHO} "Port: ${DISTVERSION}"
	@${ECHO} -n "Upstream: "
	@curl -s -I https://dl.digdag.io/digdag-latest | \
		${SED} -n 's|.*digdag-\([0-9.]*\).jar|\1|p'

.include <bsd.port.mk>
