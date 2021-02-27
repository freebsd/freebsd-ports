# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	jts
DISTVERSION=	1.18.1
DISTVERSIONPREFIX=	jts-
CATEGORIES=	math databases java

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	JTS Topology Suite

LICENSE=	EPL
#LICENSE_COMB=	dual

BUILD_DEPENDS=	mvn:devel/maven

USE_GITHUB=	yes
GH_ACCOUNT=	locationtech

USE_JAVA=	yes
JAVA_VERSION=	11+
NO_ARCH=	yes

VER=		${PORTVERSION:tl}
JARFILES=	core/target/jts-core app/target/jts-app io/common/target/jts-io-common lab/target/jts-lab
JARDOCFILES=	io/common/target/jts-io-common core/target/jts-core lab/target/jts-lab
PLIST_SUB=	VERSION=${VER}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-deps using: make pushToGH
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

.if (${DEV_UPDATE_MODE} == "yes")
pre-build:
	mkdir -p ${WRKDIR}/.m2
	cd ${WRKDIR}/.m2 && rm -Rf .git
	cd ${WRKDIR}/.m2 && git init
	cd ${WRKDIR}/.m2 && git remote add origin git@github.com:mfechner/freebsd-math-jts-deps.git
	cd ${WRKDIR}/.m2 && git fetch
	cd ${WRKDIR}/.m2 && rm -Rf repository
	cd ${WRKDIR}/.m2 && git checkout master
	cd ${WRKDIR}/.m2 && rm -Rf repository
	
post-build:
	@${ECHO} "(!!!) Please upload the maven repo using: make pushToGH"
.else
GH_TUPLE=	mfechner:freebsd-math-jts-deps:${VER}:m2
MASTER_SITES+=  LOCAL/mfechner/:maven
MVN_ARGS=	--offline

# Move the download deps to correct destination
post-patch:
	@${MV} ${WRKDIR}/freebsd-math-jts-deps-${VER} ${WRKDIR}/.m2
.endif

#-Dmaven.repo.local=${WRKDIR}/freebsd-math-jts-deps-${VER}/
do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${MVN_ARGS} \
		-fae clean install \
		-Dmaven.test.skip=true \
		-Duser.home=${WRKDIR}

do-install:
.for jar in ${JARFILES}
	@${INSTALL_DATA} ${WRKSRC}/modules/${jar}-${VER}.jar	\
		${STAGEDIR}${JAVALIBDIR}/
.endfor
	${RLN} ${STAGEDIR}${JAVALIBDIR}/jts-core-${VER}.jar ${STAGEDIR}${JAVALIBDIR}/jts-core.jar

do-install-DOCS-on:
.for jar in ${JARDOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/modules/${jar}-${VER}-javadoc.jar	\
		${STAGEDIR}${JAVALIBDIR}/
.endfor

# Make sure you build the port before (not in poudriere, make build) with DEV_UPDATE_MODE=yes
# before you execute this target
pushToGH:
	@cd ${WRKDIR}/.m2
	cd ${WRKDIR}/.m2 && git add .
	cd ${WRKDIR}/.m2 && git status
	cd ${WRKDIR}/.m2 && git commit -m "Update deps for version ${VER}."
	read -p "Continue to push new version ${VER} to GH" dummy
	cd ${WRKDIR}/.m2 && git push -u origin master
	cd ${WRKDIR}/.m2 && git tag -f ${VER}
	cd ${WRKDIR}/.m2 && git push --tags -f

.include <bsd.port.mk>
