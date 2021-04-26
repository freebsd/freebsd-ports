PORTNAME=	fisicalab
PORTVERSION=	0.3.3
PORTREVISION=	12
CATEGORIES=	science education gnustep
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Physics simulation program for educational use

LICENSE=	GPLv3

BROKEN=		fails to configure: error: C compiler cannot create executables

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		gnustep
GNU_CONFIGURE=	yes
USE_GNUSTEP=	build gui

.include <bsd.port.mk>
