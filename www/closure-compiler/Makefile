PORTNAME=	closure-compiler
DISTVERSIONPREFIX=	v
DISTVERSION=	20220601
CATEGORIES=	www java
MASTER_SITES=	https://repo1.maven.org/maven2/com/google/javascript/${PORTNAME}/v${DISTVERSION}/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	bryan@frimin.fr
COMMENT=	Closure Compiler

LICENSE=	APACHE20

USE_JAVA=	11+

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	closure-compiler
SUB_LIST=	JAVA="${JAVA}" \
		PORTVERSION=${PORTVERSION}

NO_WRKSUBDIR=	yes

PLIST_FILES=	${DATADIR}/closure-compiler-v${PORTVERSION}.jar \
		bin/closure-compiler

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/closure-compiler ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
