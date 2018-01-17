# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mp4v2
PORTVERSION=	1.9.1
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/riggs/mp4v2

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Library and tools to read, create, and modify mp4 files

LICENSE=	MPL11

CONFLICTS=	mpeg4ip-libmp4v2-[0-9.]*
USES=		compiler:features gmake libtool tar:bzip2
MAKEFILE=	GNUmakefile
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	"FOUND_HELP2MAN=no"
CXXFLAGS+=	${COMPILER_FEATURES:Mc++11:C/.+/-Wno-error=narrowing/}

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

# GCC is broken with PCH: https://lists.freebsd.org/pipermail/svn-src-all/2015-March/101722.html
.if ${COMPILER_TYPE} == gcc
CONFIGURE_ARGS=	--disable-gch
.endif

.include <bsd.port.post.mk>
