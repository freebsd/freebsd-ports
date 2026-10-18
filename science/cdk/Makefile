PORTNAME=	cdk
DISTVERSIONPREFIX=	cdk-
DISTVERSION=	2.13
CATEGORIES=	science java
PKGNAMESUFFIX=	-chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chemistry Development Kit
WWW=		https://cdk.github.io/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	maven>0:devel/maven

USES=		java
USE_GITHUB=	yes
JAVA_VERSION=	17 # Java 8 fails on aarch64: Internal Error (assembler_aarch64.hpp:237), pid=68892, tid=0x000000000002b995 guarantee(val < (1U << nbits)) failed: Field too big for insn

MAKE_ENV+=      JAVA_HOME=${JAVA_HOME}

NO_ARCH=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-deps archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

.if (${DEV_UPDATE_MODE} != "yes")
MASTER_SITES+=	LOCAL/yuri/:deps
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:deps
MVN_ARGS=	--offline
.endif

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${MVN_ARGS} \
		-fae \
		-Dmaven.test.skip=true \
		-Duser.home=${WRKDIR} \
		install

.if (${DEV_UPDATE_MODE} == "yes")
post-build: do-test
	@cd ${WRKDIR} && ${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} .m2
	@${ECHO} "(!!!) Please upload the deps archive: ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.endif

# tests excluded below need the InChI native library, which is not available for FreeBSD aarch64
do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${MVN_ARGS} \
		-fae \
		-Duser.home=${WRKDIR} \
		-Dtest='!AbsoluteSMILESTest,!CircularFragmenterTest,!InChI*Test,!RInChI*Test' \
		-Dsurefire.failIfNoSpecifiedTests=false \
		test

do-install:
	${INSTALL_DATA} ${WRKSRC}/bundle/target/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar

# tests as of 2.13: Tests run: 27189, Failures: 0, Errors: 0, Skipped: 94

.include <bsd.port.mk>
