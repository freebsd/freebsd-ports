PORTNAME=	toml-f
DISTVERSION=	0.4.2
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TOML parser for data serialization and deserialization in Fortran
WWW=		https://toml-f.github.io/toml-f/ \
		https://github.com/toml-f/toml-f

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

BROKEN_aarch64=	cannot find an intrinsic module named 'ieee_arithmetic'

USES=		cmake:testing fortran tar:xz
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	FREEBSD_BUILD_TESTS

.include <bsd.port.mk>
