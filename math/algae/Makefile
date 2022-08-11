PORTNAME=	algae
PORTVERSION=	4.3.6
PORTREVISION=	18
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programming language for numerical analysis

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		does not build: checking for proper floating point exception handling... no
BROKEN_armv6=		does not build: checking for proper floating point exception handling... no
BROKEN_armv7=		does not build: checking for proper floating point exception handling... no

GNU_CONFIGURE=	yes
USES=		fortran

CONFIGURE_ARGS=	--disable-dlmalloc --without-fftw --without-blas \
		--without-lapack --without-bcslib --without-npsol
FFLAGS+=	-std=legacy
PLIST_SUB=	ALGAE_VERSION=${PORTVERSION}

INFO=		${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
