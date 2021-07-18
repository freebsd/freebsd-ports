PORTNAME=	thermofun
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.8
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code for calculating thermodynamic properties of materials

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json

USES=		cmake compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	thermohub

CMAKE_OFF=	TFUN_BUILD_PYTHON

.include <bsd.port.mk>
