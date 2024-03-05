PORTNAME=	jitsi
DISTVERSION=	2.3-67
CATEGORIES=	net-im java
PKGNAMESUFFIX=	-videobridge

MAINTAINER=	acm@FreeBSD.org
COMMENT=	WebRTC compatible video router or SFU
WWW=		https://jitsi.org/jitsi-videobridge

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	i386 amd64 powerpc64 powerpc64le

BUILD_DEPENDS=	maven>0:devel/maven
RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}
GH_TAGNAME=	b2d4229
USE_JAVA=	yes
JAVA_VERSION=	11

DATADIR=	${JAVASHAREDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX}

SUB_FILES+=	pkg-message
SUB_LIST+=	JAVA=${JAVA}
ETCDIR=		${PREFIX}/etc/jitsi/videobridge

USERS=		jvb ${PORTNAME}
GROUPS=		${USERS}

DEV_UPDATE_MODE=	no

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	@cd ${WRKDIR} && ${TAR} czf ${DISTDIR}/${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-deps${EXTRACT_SUFX} m2
	@${ECHO} "(!!!) Please upload the maven deps archive: ${DISTDIR}/${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/acm/:maven \
		LOCAL/grembo/:maven
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-deps${EXTRACT_SUFX}:maven
MAVEN_ARGS=	--offline
.endif

MAVEN_ARGS+=	-PbuildFatJar -DskipTests -Dassembly.skipAssembly=false
MAVEN_REPO=	-Dmaven.repo.local=${WRKDIR}/m2

do-build:
	cd ${WRKSRC}; \
		${SETENV} JAVA_VERSION=${JAVA_VERSION} mvn ${MAVEN_REPO} ${MAVEN_ARGS} package

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	cd ${WRKSRC}/jvb/lib \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/lib/{} \;
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}${PKGNAMESUFFIX}.conf.sample \
		${STAGEDIR}${ETCDIR}/${PORTNAME}${PKGNAMESUFFIX}.conf.sample
	${INSTALL_DATA} ${FILESDIR}/sip-communicator.properties.sample \
		${STAGEDIR}${ETCDIR}/sip-communicator.properties.sample
	${INSTALL_DATA} ${WRKSRC}/jvb/target/${PORTNAME}${PKGNAMESUFFIX}-2.3-SNAPSHOT-jar-with-dependencies.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}${PKGNAMESUFFIX}.jar

.include <bsd.port.mk>
