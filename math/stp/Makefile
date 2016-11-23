# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stp
PORTVERSION=	1436
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://intara.arrowdodger.ru/

MAINTAINER=	6yearold@gmail.com
COMMENT=	Decision Procedure for Bitvectors and Arrays

LICENSE=	MIT

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs

USES=		bison:build cmake perl5 tar:xz
USE_PERL5=	build
CMAKE_ARGS=	-DFL_LIBRARY=/usr/lib/libfl.a

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 1000000)
BUILD_DEPENDS+=flex>=2.5.38:textproc/flex
CMAKE_ARGS+=	-DFL_LIBRARY=${LOCALBASE}/lib/libfl.a \
		-DFLEX_INCLUDE_DIR=${LOCALBASE}/include/flex \
		-DFLEX_EXECUTABLE=${LOCALBASE}/bin/flex
.endif

.include <bsd.port.post.mk>
