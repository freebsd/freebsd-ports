PORTNAME=	XLConnect
DISTVERSION=	1.2.2
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

post-patch:
	@${REINPLACE_CMD} -e 's|JAVALIBDIR|${JAVALIBDIR}|g' ${WRKSRC}/R/onLoad.R

.include <bsd.port.mk>
