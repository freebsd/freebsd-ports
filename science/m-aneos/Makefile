PORTNAME=	m-aneos
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0-1
DISTVERSIONSUFFIX=	-g58d75bc
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	M-ANEOS: program for construction of thermodynamic equations of state
WWW=		https://github.com/isale-code/M-ANEOS

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		gmake fortran
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	isale-code
GH_PROJECT=	M-ANEOS

WRKSRC_SUBDIR=	src

MAKE_ARGS=	FC=${FC} FCFLAGS="${FFLAGS}"

ALL_TARGET=	default

PLIST_FILES=	bin/m-aneos

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/m-aneos ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
