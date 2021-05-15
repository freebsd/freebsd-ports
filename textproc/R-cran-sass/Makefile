PORTNAME=	sass
PORTVERSION=	0.4.0
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Syntactically Awesome Style Sheets ('Sass')

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-fs>0:sysutils/R-cran-fs \
		R-cran-rlang>=0.4.10:devel/R-cran-rlang \
		R-cran-htmltools>=0.5.1:textproc/R-cran-htmltools \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rappdirs>0:devel/R-cran-rappdirs
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
