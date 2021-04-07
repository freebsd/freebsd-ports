PORTNAME=	opsin
DISTVERSION=	3.0.20190223
CATEGORIES=	science java
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${PORTNAME}/get/${BB_COMMIT}${EXTRACT_SUFX}?dummy=/:src
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Parser for Systematic IUPAC Nomenclature of chemical names

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	mvn:devel/maven

USE_JAVA=	yes

NO_ARCH=	yes

BB_ACCOUNT=	dan2097
BB_COMMIT=	9b25f7546b67

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${PORTNAME}-${BB_COMMIT}
SUB_FILES=	${PORTNAME}
SUB_LIST=	JAVA=${JAVA} PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}-jar-with-dependencies.jar

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-deps archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	@cd ${WRKDIR} && ${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} .m2
	@${ECHO} "(!!!) Please upload the maven deps archive: ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/yuri/:maven
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:maven
MVN_ARGS=	--offline
.endif

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${MVN_ARGS} \
		-fae install \
		-Dmaven.test.skip=true \
		-Duser.home=${WRKDIR} \
		package assembly:assembly

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-*-jar-with-dependencies.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}-jar-with-dependencies.jar

.include <bsd.port.mk>
