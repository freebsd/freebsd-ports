PORTNAME=	yaml
DISTVERSION=	2.3.11
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Methods to convert R data to YAML and back
WWW=		https://cran.r-project.org/package=yaml

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	R-cran-RUnit>0:devel/R-cran-RUnit

USES=		compiler:c++23-lang cran:auto-plist,compiles

.include <bsd.port.mk>
