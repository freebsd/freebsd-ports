# Created by: Michael Neumann <mneumann@ntecs.de>
# $FreeBSD$

PORTNAME=	algae
PORTVERSION=	4.3.6
PORTREVISION=	9
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programming language for numerical analysis

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

BROKEN_ia64=	does not compile
BROKEN_powerpc=	does not compile
BROKEN_sparc64=	does not compile

GNU_CONFIGURE=	yes
USES=		fortran

CONFIGURE_ARGS=	--disable-dlmalloc --without-fftw --without-blas \
		--without-lapack --without-bcslib --without-npsol
PLIST_SUB=	ALGAE_VERSION=${PORTVERSION}

INFO=		${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
