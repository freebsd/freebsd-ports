PORTNAME=	zaproxy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.1
CATEGORIES=	security java

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The OWASP zed attack proxy

LICENSE=	APACHE20

BUILD_DEPENDS=	gradle:devel/gradle

USES=		gettext-runtime
USE_JAVA=	yes

USE_GITHUB=	yes

JAVA_VERSION=	11

NO_ARCH=	yes

MAKE_ENV+=	GRADLE_USER_HOME=${WRKDIR}

DESKTOP_ENTRIES="ZAP" "OWASP ZAP" "${PREFIX}/share/pixmaps/zaproxy.png" "${PORTNAME}" \
		"System;Security;" true

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-deps archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

DEPS_CACHE_DIR=	${WRKDIR}

MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	@cd ${DEPS_CACHE_DIR} && ${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} gradle-${PORTNAME}
	@cd ${WRKSRC}/zap/build && ${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-plugins${EXTRACT_SUFX} mainAddOns
	@${ECHO} "(!!!) Please upload the deps archive: ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
	@${ECHO} "(!!!) Please upload the plugins archive: ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-plugins${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/acm/${PORTNAME}:deps
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:deps \
		${PORTNAME}-${DISTVERSION}-plugins${EXTRACT_SUFX}:deps
GRADLE_ARGS=	--offline

post-extract: # need a separate extract step because the cache is in /tmp, and not under work/ like with maven
	@cd ${DEPS_CACHE_DIR} && ${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}

post-patch:
	@${ECHO} "" > ${WRKSRC}/zap/src/main/add-ons.txt
	@${REINPLACE_CMD} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g' \
		-e 's|%%JAVA_HOME%%|${JAVA_HOME}|g' \
		-e 's|%%VERSION%%|${DISTVERSION}|g' ${WRKSRC}/zap/src/main/dist/zap.sh
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gradle \
		--gradle-user-home ${DEPS_CACHE_DIR}/gradle-${PORTNAME} --project-cache-dir ${DEPS_CACHE_DIR}/gradle-${PORTNAME} \
		${GRADLE_ARGS} --build-cache :zap:distCore

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zap/build/distFiles/zap.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/zap/build/distFiles/ && ${COPYTREE_SHARE} "db lang lib license plugin README scripts xml zap-${DISTVERSION}.jar" ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	cd ${WRKDIR}/mainAddOns && ${COPYTREE_SHARE} ./ ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/plugin
	${INSTALL_DATA} ${WRKSRC}/zap/src/main/resources/resource/zap64x64.png ${STAGEDIR}${PREFIX}/share/pixmaps/zaproxy.png

.include <bsd.port.mk>
