PORTNAME=	XLConnect
PORTVERSION=	1.0.5
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	R package for manipulating Microsoft Excel files

LICENSE=	GPLv3

BUILD_DEPENDS=	R-cran-rJava>0:devel/R-cran-rJava
RUN_DEPENDS=	R-cran-rJava>0:devel/R-cran-rJava	\
		apache-poi>0:textproc/apache-poi	\
		SparseBitSet>0:devel/sparsebitset	\
		apache-xmlbeans>0:textproc/apache-xmlbeans	\
		apache-commons-math>0:math/apache-commons-math	\
		apache-commons-codec>0:java/apache-commons-codec	\
		apache-commons-compress>0:archivers/apache-commons-compress \
		apache-commons-collections4>0:java/apache-commons-collections4

USES=		cran
USE_JAVA=	yes

DEP_JARS=	commons-codec commons-collections4 commons-compress	\
		ooxml-schemas poi poi-ooxml poi-ooxml-schemas		\
		SparseBitSet xmlbeans

post-install:
.for j in ${DEP_JARS}
	${LN} -sf ${JAVALIBDIR}/${j}.jar ${STAGEDIR}${PREFIX}/${R_MOD_DIR}/java/
.endfor
	${LN} -sf ${JAVALIBDIR}/commons-math.jar	\
		${STAGEDIR}${PREFIX}/${R_MOD_DIR}/java/commons-math3.jar

.include <bsd.port.mk>
