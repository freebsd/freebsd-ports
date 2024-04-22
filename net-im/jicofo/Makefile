PORTNAME=	jicofo
DISTVERSION=	1.0-1062
CATEGORIES=	net-im java

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Server side focus component used in Jitsi Meet conferences
WWW=		https://github.com/jitsi/jicofo/

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	i386 amd64 powerpc64 powerpc64le

BUILD_DEPENDS=	maven>0:devel/maven

USE_GITHUB=	yes
GH_ACCOUNT=	jitsi
GH_TAGNAME=	258eb98
USE_JAVA=	yes
JAVA_VERSION=	11

USE_RC_SUBR=	${PORTNAME}
SUB_FILES+=	pkg-message
SUB_LIST+=	JAVA=${JAVA}
ETCDIR=		${PREFIX}/etc/jitsi/jicofo

USERS=		${PORTNAME} jitsi
GROUPS=		${USERS}

DEV_UPDATE_MODE=	no

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	@cd ${WRKDIR} && ${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} m2
	@${ECHO} "(!!!) Please upload the maven deps archive: ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/acm/:maven \
		LOCAL/grembo/:maven
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:maven
MAVEN_ARGS=	--offline
.endif

MAVEN_ARGS+=	-DskipTests -Dassembly.skipAssembly=false
MAVEN_REPO=	-Dmaven.repo.local=${WRKDIR}/m2

do-build:
	cd ${WRKSRC}; \
		${SETENV} JAVA_VERSION=${JAVA_VERSION} mvn ${MAVEN_REPO} ${MAVEN_ARGS} package

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	cd ${WRKSRC}/lib \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/lib/{} \;

	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${WRKSRC}/jicofo/target/${PORTNAME}-1.1-SNAPSHOT-jar-with-dependencies.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
