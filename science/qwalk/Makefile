PORTNAME=	qwalk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1-300
PORTREVISION=	6
DISTVERSIONSUFFIX=	-g1b7e381
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum Monte Carlo package for quantum chemistry computations
WWW=		https://qwalk.github.io/mainline/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

PORTSCOUT=	limit:^.*[1-9]\. # prevent words like 'broken'

USES=		compiler:c++11-lang fortran gmake gnome perl5
USE_GNOME=	libxml2
USE_CXXSTD=	c++11 # attempt to fix failure: Cubic_spline_calc.cpp:1107:5: error: ISO C++17 does not allow 'register' storage class specifier

USE_GITHUB=	yes
GH_ACCOUNT=	QWalk
GH_PROJECT=	mainline

WRKSRC_SUBDIR=	src
MAKE_ARGS=	INSTALLPATH=${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
