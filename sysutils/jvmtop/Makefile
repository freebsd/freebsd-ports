PORTNAME=	jvmtop
DISTVERSION=	0.8.0-27
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g5693965
CATEGORIES=	sysutils java
MASTER_SITES=	SF/bsdsrc/jvmtop:source2
DISTFILES=	jvmtop-maven-repository-${BUILD}.tar.gz:source2

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Lightweight console application to monitor running jvms
WWW=		https://github.com/patric-r/jvmtop

LICENSE=	GPLv2

BUILD_DEPENDS=	maven>0:devel/maven

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USES=		java

NO_ARCH=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar \
		bin/${PORTNAME}
SUB_LIST=	JAVA_HOME=${JAVA_HOME}
SUB_FILES=	${PORTNAME}.sh
BUILD=	0.9.0

GH_ACCOUNT=	patric-r
USE_GITHUB=	yes
JAVA_VERSION=	8

post-extract:
	@${TAR} -xf ${DISTDIR}/jvmtop-maven-repository-${BUILD}.tar.gz -C ${WRKSRC}

do-build:
	cd ${WRKSRC} && JAVA_HOME=${JAVA_HOME} ${LOCALBASE}/bin/mvn -o -Dmaven.repo.local=.m2/repository ${INSTALL}

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-${BUILD}-SNAPSHOT.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
