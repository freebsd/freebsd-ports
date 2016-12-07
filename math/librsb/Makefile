# Created by: stephen@FreeBSD.org
# $FreeBSD$

PORTNAME=	librsb
PORTVERSION=	1.2.0r4
PORTREVISION=	2
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
		--enable-matrix-types="double, double complex" \
		--with-memhinfo="${RSB_USER_SET_MEM_HIERARCHY_INFO}"
SHEBANG_FILES=	scripts/*.sh

MANUAL_PACKAGE_BUILD=	Optimizes for the local machine

pre-configure:
	@if [ -z "${RSB_USER_SET_MEM_HIERARCHY_INFO}" ]; then \
		${CAT} ${FILESDIR}/memhinfo.txt; \
		exit 1; \
	fi

post-patch:
	@${REINPLACE_CMD} -E s/sed/gsed/g ${WRKSRC}/scripts/*.sh

check regression-test test: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} qtests

.include <bsd.port.mk>
