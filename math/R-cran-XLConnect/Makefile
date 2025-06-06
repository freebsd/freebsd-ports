PORTNAME=	XLConnect
PORTVERSION=	1.2.2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	R package for manipulating Microsoft Excel files
WWW=		https://cran.r-project.org/package=XLConnect

LICENSE=	GPLv3

BUILD_DEPENDS=	R-cran-rJava>0:devel/R-cran-rJava
RUN_DEPENDS=	R-cran-rJava>0:devel/R-cran-rJava	\
		apache-poi>0:textproc/apache-poi	\
		SparseBitSet>0:devel/sparsebitset	\
		apache-xmlbeans>0:textproc/apache-xmlbeans	\
		apache-commons-io>0:devel/apache-commons-io	\
		apache-commons-math>0:math/apache-commons-math	\
		apache-commons-codec>0:java/apache-commons-codec	\
		apache-commons-lang3>0:java/apache-commons-lang3	\
		apache-commons-compress>0:archivers/apache-commons-compress \
		apache-commons-collections4>0:java/apache-commons-collections4
TEST_DEPENDS=	R-cran-zoo>0:math/R-cran-zoo	\
		R-cran-RUnit>0:devel/R-cran-RUnit	\
		R-cran-ggplot2>0:graphics/R-cran-ggplot2

USES=		cran java

# See PR 272855
BROKEN=		a recent default JDK is required for a full apache-poi with bouncycastle

DEP_JARS=	commons-codec commons-collections4 commons-compress commons-io	\
		commons-lang3 commons-math log4j-api poi poi-ooxml poi-ooxml-full\
		SparseBitSet xmlbeans

post-stage:
.for j in ${DEP_JARS}
	${LN} -sf ${JAVALIBDIR}/${j}.jar ${STAGEDIR}${PREFIX}/${R_MOD_DIR}/java/
.endfor
	${LN} -sf ${JAVALIBDIR}/commons-lang3.jar	\
		${STAGEDIR}${PREFIX}/${R_MOD_DIR}/java/commons-lang3-3.16.0.jar
	${LN} -sf ${JAVALIBDIR}/commons-math.jar	\
		${STAGEDIR}${PREFIX}/${R_MOD_DIR}/java/commons-math3.jar
	${LN} -sf ${JAVALIBDIR}/commons-io.jar	\
		${STAGEDIR}${PREFIX}/${R_MOD_DIR}/java/commons-io-2.18.0.jar
	${LN} -sf ${JAVALIBDIR}/commons-codec.jar	\
		${STAGEDIR}${PREFIX}/${R_MOD_DIR}/java/commons-codec-1.18.0.jar

.include <bsd.port.mk>
