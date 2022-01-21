# Created by: stephen@FreeBSD.org

PORTNAME=	librsb
PORTVERSION=	1.2.0.11
CATEGORIES=	math
MASTER_SITES=	SF/librsb
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/-rc/}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Sparse matrix library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed \
		bash:shells/bash

USES=		fortran gmake shebangfix libtool
USE_GCC=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	qtests
GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--enable-fortran-module-install \
		--enable-matrix-types="double, double complex"
CONFIGURE_ENV=	CFLAGS= SPCFLAGS="${CFLAGS}"
SHEBANG_FILES=	scripts/*.sh examples/make.sh.in
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS OPTIMIZE

OPTIMIZE_DESC=		Optimize for the local machine
OPTIMIZE_CONFIGURE_ENV=	SPCFLAGS="${CFLAGS:N-O*}"

post-patch:
	@${REINPLACE_CMD} -E s/sed/gsed/g ${WRKSRC}/scripts/*.sh

post-patch-OPTIMIZE-on:
	@${REINPLACE_CMD} s/enable_optimize=no/enable_optimize=yes/ \
		${WRKSRC}/configure

.include <bsd.port.mk>
