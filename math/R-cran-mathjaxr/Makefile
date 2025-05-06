PORTNAME=	mathjaxr
DISTVERSION=	1.8-0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Using 'Mathjax' in Rd Files
WWW=		https://cran.r-project.org/web/packages/mathjaxr/

LICENSE=	GPLv3+

USES=		cran:auto-plist,compiles

post-install:
	${ECHO} "@dir lib/R/library/mathjaxr/libs" >>${TMPPLIST}

.include <bsd.port.mk>
