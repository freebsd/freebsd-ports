# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stp
PORTVERSION=	1436
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	http://intara.arrowdodger.ru/

MAINTAINER=	6yearold@gmail.com
COMMENT=	Decision Procedure for Bitvectors and Arrays

LICENSE=	MIT

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs

USES=		bison:build cmake:noninja perl5 tar:xz
USE_PERL5=	build
CMAKE_ARGS=	-DFL_LIBRARY=/usr/lib/libfl.a

BROKEN_aarch64=		Fails to compile: undefined reference to sbrk

.include <bsd.port.mk>
