# $FreeBSD$

PORTNAME=	jicofo
DISTVERSION=	1.0-555
PORTREVISION=	2
CATEGORIES=	net-im java

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Server side focus component used in Jitsi Meet conferences

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven/bin/mvn:devel/maven

ONLY_FOR_ARCHS=	i386 amd64

USE_GITHUB=     yes
GH_ACCOUNT=	jitsi
GH_PROJECT=     jicofo
GH_TAGNAME=	ec1b29e
USE_JAVA=	yes

USE_RC_SUBR=	${PORTNAME}
SUB_FILES+=	pkg-message
SUB_LIST+=	JAVA=${JAVA}
ETCDIR=		${PREFIX}/etc/jitsi/jicofo

DEV_UPDATE_MODE=	no

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	@cd ${WRKDIR} && ${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} m2
	@${ECHO} "(!!!) Please upload the maven deps archive: ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/acm/:maven
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:maven
MAVEN_ARGS=	--offline
.endif

MAVEN_ARGS+=	-DskipTests -Dassembly.skipAssembly=false
MAVEN_REPO=	-Dmaven.repo.local=${WRKDIR}/m2

do-build:
	cd ${WRKSRC}; \
		${SETENV} mvn ${MAVEN_REPO} ${MAVEN_ARGS} package

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	cd ${WRKSRC}/lib \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/lib/{} \;

	@(echo "JVB_XMPP_HOST=localhost"; \
	echo "JVB_XMPP_DOMAIN=jitsi.example.com"; \
	echo "JVB_XMPP_PORT=5347"; \
	echo "JVB_XMPP_SECRET=YOURSECRET3"; \
	echo "JVB_XMPP_USER_DOMAIN=auth.jitsi.example.com"; \
	echo "JVB_XMPP_USER_NAME=focus"; \
	echo "JVB_XMPP_USER_SECRET=YOURSECRET3"; \
        echo ""; \
        echo "MAX_MEMORY=3072m"; \
        ) > ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

	${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-1.1-SNAPSHOT-jar-with-dependencies.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
 	
.include <bsd.port.mk>
