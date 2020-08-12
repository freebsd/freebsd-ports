# Created by: stephen@FreeBSD.org
# $FreeBSD$

PORTNAME=	librsb
PORTVERSION=	1.2.0.9
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
TEST_TARGET=	qtests
GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--enable-fortran-module-install \
		--enable-matrix-types="double, double complex"
SHEBANG_FILES=	scripts/*.sh examples/make.sh.in
USE_LDCONFIG=	yes

MANUAL_PACKAGE_BUILD=	Optimizes for the local machine

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E s/sed/gsed/g ${WRKSRC}/scripts/*.sh

.include <bsd.port.mk>
