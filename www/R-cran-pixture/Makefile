PORTNAME=	pixture
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	www

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Responsive HTML Image Gallery
WWW=		https://www.royfrancis.com/pixture/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	R-cran-htmlwidgets>0:www/R-cran-htmlwidgets \
		R-cran-shiny>0:www/R-cran-shiny
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist
USE_GITHUB=	yes
GH_ACCOUNT=	royfrancis
# The cran.mk overrides it.
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

# The cran.mk's do-install and do-test want use directory ${PORTNAME}
# instead of ${PORTNAME}-${DISTVERSION}.
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${R_LIB_DIR}
	@cd ${WRKDIR} ; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${R_COMMAND} \
	${R_PRECMD_INSTALL_OPTIONS} CMD INSTALL \
	-l ${STAGEDIR}${PREFIX}/${R_LIB_DIR} ${PORTNAME}-${DISTVERSION}

do-test:
	@${FIND} ${WRKSRC} \( -name '*.o' -o -name '*.so' \) -delete
	@cd ${WRKDIR} ; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} _R_CHECK_FORCE_SUGGESTS_=FALSE \
	${R_COMMAND} ${R_PRECMD_CHECK_OPTIONS} CMD check \
	--no-manual --no-build-vignettes ${PORTNAME}-${DISTVERSION}

.include <bsd.port.mk>
