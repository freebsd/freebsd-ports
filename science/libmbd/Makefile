PORTNAME=	libmbd
DISTVERSION=	0.12.5
PORTREVISION=	2
CATEGORIES=	science # chemistry
MASTER_SITES=	https://github.com/libmbd/libmbd/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Many-body dispersion library
WWW=		https://github.com/libmbd/libmbd

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake:testing fortran

do-test: # fails to find tests, see https://github.com/libmbd/libmbd/issues/43
	@cd ${BUILD_WRKSRC} && ctest --test-dir .

.include <bsd.port.mk>
