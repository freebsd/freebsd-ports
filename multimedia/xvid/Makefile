# New ports collection makefile for:	xvid
# Date created:		04 April 2002
# Whom:			Michael Nottebrock <michaelnottebrock@gmx.net> et al
#
# $FreeBSD$
#

PORTNAME=	xvid
PORTVERSION=	1.0.3
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.xvid.org/downloads/
DISTNAME=	${PORTNAME}core-${PORTVERSION}

MAINTAINER=	lofi@freebsd.org
COMMENT=	An opensource MPEG-4 codec, based on OpenDivx

BUILD_DEPENDS=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GCC?=	3.4

WRKSRC=			${WRKDIR}/${DISTNAME}/build/generic

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS=		# let xvid's build system decide about those
.endif

post-install:
	@ ${LN} -sf ${PREFIX}/lib/libxvidcore.so.4 ${PREFIX}/lib/libxvidcore.so

.include <bsd.port.mk>
