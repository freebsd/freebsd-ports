# $FreeBSD$

PORTNAME=	jitsi
DISTVERSION=	2.1-183
PORTREVISION=	3
CATEGORIES=	net-im java
PKGNAMESUFFIX=	-videobridge

MAINTAINER=	acm@FreeBSD.org
COMMENT=	WebRTC compatible video router or SFU

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven/bin/mvn:devel/maven
RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

ONLY_FOR_ARCHS=	i386 amd64

USE_GITHUB=     yes
GH_PROJECT=     ${PORTNAME}${PKGNAMESUFFIX}
GH_TAGNAME=	dbddd16
USE_JAVA=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX}

SUB_FILES+=	pkg-message
SUB_LIST+=	JAVA=${JAVA}
ETCDIR=		${PREFIX}/etc/jitsi/videobridge

DEV_UPDATE_MODE=        no

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	@cd ${WRKDIR} && ${TAR} czf ${DISTDIR}/${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-deps${EXTRACT_SUFX} m2
	@${ECHO} "(!!!) Please upload the maven deps archive: ${DISTDIR}/${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/acm/:maven
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-deps${EXTRACT_SUFX}:maven
MAVEN_ARGS=	--offline
.endif

MAVEN_ARGS+=	-PbuildFatJar -DskipTests -Dassembly.skipAssembly=false
MAVEN_REPO=	-Dmaven.repo.local=${WRKDIR}/m2

post-patch:
	@${REINPLACE_CMD} -e 's|1.0-20190319.172750-1|1.0-0-ge979298|g' ${WRKSRC}/pom.xml

do-build:
	cd ${WRKSRC}; \
		${SETENV} mvn ${MAVEN_REPO} ${MAVEN_ARGS} package

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	cd ${WRKSRC}/lib \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/lib/{} \;

	@(echo "JVB_XMPP_HOST=localhost"; \
	echo "JVB_XMPP_DOMAIN=jitsi.example.com"; \
	echo "JVB_XMPP_PORT=5347"; \
	echo "JVB_XMPP_SECRET=YOURSECRET1"; \
	echo ""; \
	echo "VIDEOBRIDGE_MAX_MEMORY=3072m"; \
	echo "# VIDEOBRIDGE_DEBUG_OPTIONS=\"-Xdebug -Xrunjdwp:transport=dt_socket,server=y,suspend=n,address=8000\" "; \
	) > ${STAGEDIR}${ETCDIR}/${PORTNAME}${PKGNAMESUFFIX}.conf.sample

	${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}${PKGNAMESUFFIX}-2.1-SNAPSHOT-jar-with-dependencies.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}${PKGNAMESUFFIX}.jar
 	
.include <bsd.port.mk>
