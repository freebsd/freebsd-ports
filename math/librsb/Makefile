# Created by: stephen@FreeBSD.org
# $FreeBSD$

PORTNAME=	librsb
PORTVERSION=	1.2.0r7
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/librsb
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/-rc/}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Sparse matrix library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed \
		bash:shells/bash

USES=		fortran compiler:openmp gmake shebangfix libtool
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--enable-fortran-module-install \
		--enable-matrix-types="double, double complex"
SHEBANG_FILES=	scripts/*.sh
USE_LDCONFIG=	yes

MANUAL_PACKAGE_BUILD=	Optimizes for the local machine

post-patch:
	@${REINPLACE_CMD} -E s/sed/gsed/g ${WRKSRC}/scripts/*.sh

check regression-test test: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} qtests

.include <bsd.port.mk>
