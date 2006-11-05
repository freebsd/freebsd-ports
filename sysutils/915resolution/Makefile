# New ports collection makefile for:	915resolution
# Date created:				30 Apr 2004
# Whom:					Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$

PORTNAME=	915resolution
PORTVERSION=	0.5.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.geocities.com/stomljen/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ehaupt

MAINTAINER=	MrL0Lz@gmail.com
COMMENT=	Resolution tool for Intel i915 video cards

PLIST_FILES=	bin/915resolution
ALL_TARGET=	915resolution

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not build
.endif

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} 915resolution.c -o 915resolution

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/915resolution ${PREFIX}/bin

.include <bsd.port.post.mk>
