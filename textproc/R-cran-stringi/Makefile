PORTNAME=	stringi
DISTVERSION=	1.8.7
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Character String Processing Facilities
WWW=		https://cran.r-project.org/package=stringi

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicui18n.so:devel/icu

USES=		compiler:c++17-lang cran:auto-plist,compiles pkgconfig:build

.include <bsd.port.mk>
