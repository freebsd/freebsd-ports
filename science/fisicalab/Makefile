PORTNAME=	fisicalab
PORTVERSION=	0.3.3
PORTREVISION=	14
CATEGORIES=	science education gnustep
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Physics simulation program for educational use
WWW=		https://www.nongnu.org/fisicalab/

LICENSE=	GPLv3

BROKEN=		fails to configure: error: C compiler cannot create executables
DEPRECATED=	Broken since 2021
EXPIRATION_DATE=	2023-03-21

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		gnustep
GNU_CONFIGURE=	yes
USE_GNUSTEP=	build gui

.include <bsd.port.mk>
