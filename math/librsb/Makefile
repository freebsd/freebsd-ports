# Created by: stephen@FreeBSD.org
# $FreeBSD$

PORTNAME=	librsb
PORTVERSION=	1.2.0r1
CATEGORIES=	math
MASTER_SITES=	SF/librsb
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/-rc/}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Sparse matrix library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

USES=		fortran compiler:openmp gmake shebangfix
GNU_CONFIGURE=	yes
CFLAGS=		-fPIC
CONFIGURE_ARGS=	--enable-fortran-module-install \
		--enable-matrix-types="double, double complex"
SHEBANG_FILES=	scripts/*.sh

post-patch:
	@${REINPLACE_CMD} -E s/sed/gsed/g ${WRKSRC}/scripts/*.sh

.include <bsd.port.mk>
