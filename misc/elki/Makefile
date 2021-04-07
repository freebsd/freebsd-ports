PORTNAME=	elki
DISTVERSIONPREFIX=	release
DISTVERSION=	0.7.1-1166
DISTVERSIONSUFFIX=	-gfb1fffdf3
CATEGORIES=	misc java
MASTER_SITES=	LOCAL/yuri/:deps
DISTFILES=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:deps
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data mining toolkit

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	gradle5:devel/gradle5

USE_JAVA=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	elki-project

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} JAVA=${JAVA}

DEPS_CACHE_DIR=	/tmp # should be ${WRKDIR}, but workaround for the gradle bug that dependency cache is not relocable: https://github.com/gradle/gradle/issues/1338

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar

# to rebuild the deps archive:
#   1. remove post-extract
#   2. remove --offline
#   3. remove MASTER_SITES/DISTFILES/EXTRACT_ONLY
#   4. build
#   5. package ${DEPS_CACHE_DIR}/gradle-${PORTNAME} into the deps archive and upload it
#   6. restore the removed items

post-extract:
	@cd ${DEPS_CACHE_DIR} && ${TAR} xzf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gradle5 \
		--gradle-user-home ${DEPS_CACHE_DIR}/gradle-${PORTNAME} --project-cache-dir ${DEPS_CACHE_DIR}/gradle-${PORTNAME} \
		--offline --build-cache shadowJar

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-bundle-0.7.2-SNAPSHOT.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar

.include <bsd.port.mk>
