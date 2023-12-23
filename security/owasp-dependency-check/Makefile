# Note to committers:
# With each version update, a new maven repository must be created and distributed
# so build is repeatable and cluster-safe.

PORTNAME=	owasp-dependency-check
PORTVERSION=	3.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security java
MASTER_SITES=	LOCAL/pi/:source2
DISTFILES+=	owasp-dependency-check-${PORTVERSION}-maven-repository.tar.gz:source2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Detects publicly disclosed vulnerabilities in project dependencies
WWW=		https://jeremylong.github.io/DependencyCheck \
		https://www.owasp.org/index.php/OWASP_Dependency_Check \
		https://jeremylong.github.io/DependencyCheck/dependency-check-cli/

LICENSE=	APACHE20

BUILD_DEPENDS=	mvn:devel/maven

USE_GITHUB=	yes
GH_ACCOUNT=	jeremylong
GH_PROJECT=	DependencyCheck
USE_JAVA=	yes

NO_ARCH=	yes
SUB_FILES=	owasp-dependency-check
SUB_LIST=	PORTVERSION=${PORTVERSION}

PLIST_DIRS=	/var/cache/owasp-dependency-check
PLIST_FILES=	bin/owasp-dependency-check \
		${JAVAJARDIR}/owasp-dependency-check-${PORTVERSION}-jar-with-dependencies.jar

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mvn \
		--batch-mode -Dmaven.repo.local=${WRKDIR}/repository -DskipTests --offline package

do-install:
	${INSTALL_DATA} ${WRKSRC}/dependency-check-cli/target/dependency-check-${PORTVERSION}-jar-with-dependencies.jar \
		${STAGEDIR}${JAVAJARDIR}/owasp-dependency-check-${PORTVERSION}-jar-with-dependencies.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}/var/cache/owasp-dependency-check

.include <bsd.port.mk>
