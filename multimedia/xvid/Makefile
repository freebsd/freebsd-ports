# New ports collection makefile for:	xvid
# Date created:		04 April 2002
# Whom:			Michael Nottebrock <michaelnottebrock@gmx.net> et al
#
# $FreeBSD$
#

PORTNAME=	xvid
PORTVERSION=	1.2.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xvid.org/downloads/
DISTNAME=	${PORTNAME}core-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	An opensource MPEG-4 codec, based on OpenDivx

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	include/xvid.h \
		lib/libxvidcore.a \
		lib/libxvidcore.so \
		lib/libxvidcore.so.4

WRKSRC=		${WRKDIR}/xvidcore/build/generic

OPTIONS=	OPTIMIZED_CFLAGS "Use XviD's default optimizations" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif
.if ${ARCH} == "amd64" || ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS=		# let xvid's build system decide about those
.endif

post-install:
	@ ${LN} -sf ${PREFIX}/lib/libxvidcore.so.4 ${PREFIX}/lib/libxvidcore.so

.include <bsd.port.post.mk>
