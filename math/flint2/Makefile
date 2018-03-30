# $FreeBSD$

PORTNAME=	flint2
DISTVERSION=	g20170804
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	d900af4ca348b054c0e6b2a6645a54744ec9e74b.patch:-p1 # fix 32-bit failure: https://github.com/fredrik-johansson/flint2/pull/22

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast library for number theory

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
GH_ACCOUNT=	fredrik-johansson
GH_TAGNAME=	5f2a264
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libflint.so.*

.include <bsd.port.mk>
