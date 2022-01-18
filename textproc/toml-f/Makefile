PORTNAME=	toml-f
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2-4
DISTVERSIONSUFFIX=	-gf066ec6
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TOML parser for data serialization and deserialization in Fortran

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cmake:testing fortran
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
