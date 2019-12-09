# $FreeBSD$

PORTNAME=	sisl
DISTVERSIONPREFIX=	SISL-
DISTVERSION=	4.6.0-44
DISTVERSIONSUFFIX=	-g9114631
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spline library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	SINTEF-Geometry
GH_PROJECT=	SISL
USE_LDCONFIG=	yes

PLIST_FILES=	include/sisl-copyright.h \
		include/sisl.h \
		include/sislP.h \
		lib/libsisl.so

.include <bsd.port.mk>
