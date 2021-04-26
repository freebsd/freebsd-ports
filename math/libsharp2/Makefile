PORTNAME=	libsharp2
DISTVERSION=	g20191210
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for fast spherical harmonic transforms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
USE_GITLAB=	yes

GL_SITE=	https://gitlab.mpcdf.mpg.de
GL_ACCOUNT=	mtr
GL_PROJECT=	libsharp
GL_COMMIT=	54856313a5fcfb6a33817b7dfa28c4b1965ffbd1

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
