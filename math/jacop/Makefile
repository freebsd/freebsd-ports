PORTNAME=	jacop
DISTVERSIONPREFIX=	v
DISTVERSION=	4.8.0
CATEGORIES=	math java
MASTER_SITES=	LOCAL/yuri/:maven \
		http://people.freebsd.org/~yuri/:maven

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Java Constraint Programming solver

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	mvn:devel/maven

USE_JAVA=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	radsz

NO_ARCH=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	PORTVERSION=${PORTVERSION} JAVA=${JAVA}

PLIST_SUB=	VERSION=${PORTVERSION}

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
		compile

do-install:
	# script
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/fzn-${PORTNAME}
	# jar
	${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar
	# MiniZinc config file
	${MKDIR} ${STAGEDIR}${PREFIX}/share/minizinc/solvers
	${INSTALL_DATA} ${WRKSRC}/src/main/minizinc/org.jacop.msc ${STAGEDIR}${PREFIX}/share/minizinc/solvers
	# jacop library
	cd ${WRKSRC}/src/main/minizinc/org/jacop/minizinc && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/minizinc/jacop

.include <bsd.port.mk>
