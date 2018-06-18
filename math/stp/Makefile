# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stp
PORTVERSION=	1436
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	http://intara.arrowdodger.ru/

MAINTAINER=	6yearold@gmail.com
COMMENT=	Decision Procedure for Bitvectors and Arrays

LICENSE=	MIT

BROKEN_aarch64=		fails to compile: undefined reference to sbrk
BROKEN_powerpc64=	fails to compile: main.cpp.o: undefined reference to boost::program_options::error_with_option_name::get_canonical_option_name()

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs

USES=		bison:build cmake:noninja perl5 tar:xz
USE_PERL5=	build
CMAKE_ARGS=	-DFL_LIBRARY=/usr/lib/libfl.a

.include <bsd.port.mk>
