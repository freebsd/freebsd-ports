PORTNAME=	libmbd
DISTVERSION=	0.12.4
CATEGORIES=	science # chemistry
MASTER_SITES=	https://github.com/libmbd/libmbd/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Many-body dispersion library

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake:testing fortran

.include <bsd.port.mk>
