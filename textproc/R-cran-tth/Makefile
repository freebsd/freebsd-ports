PORTNAME=	tth
DISTVERSION=	4.12-0-1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	R wrappers for the tth/ttm TeX-to-HTML/MathML translators
WWW=		https://cran.r-project.org/web/packages/tth/

LICENSE=	GPLv2

USES=		cran:auto-plist,compiles

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/tth/libs/tth
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/tth/libs/ttm

.include <bsd.port.mk>
