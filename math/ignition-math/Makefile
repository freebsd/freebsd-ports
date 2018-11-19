# $FreeBSD$

PORTNAME=	ignition-math
DISTVERSION=	6.0.0
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General purpose math library for robot applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ignition-cmake==2:devel/ignition-cmake

USES=		cmake:outsource eigen:3
USE_LDCONFIG=	yes

BB_ACCOUNT=	ignitionrobotics
BB_PROJECT=	ign-math
BB_COMMIT=	46f3dd24499c

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

PLIST_SUB+=	IGN_VER=${DISTVERSION:R:R}

.include <bsd.port.mk>
