# New ports collection makefile for:	libgmp
# Date created:				28 August 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgmp
PORTVERSION=	2001.08.07
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for arbitrary precision arithmetic

NO_LATEST_LINK=	yes
CONFLICTS=	libgmp-4*
ONLY_FOR_ARCHS=	alpha i386
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
MAKE_FLAGS=	INCDIR=${PREFIX}/include \
		LIBDIR=${PREFIX}/lib \
		INFODIR=${PREFIX}/info

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"is in the base system"
.endif

.include <bsd.port.post.mk>
