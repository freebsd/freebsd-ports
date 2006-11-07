# New ports collection makefile for:	libpri
# Date created:				25 Oct 2004
# Whom:					Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	libpri
PORTVERSION=	1.2.3
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.digium.com/pub/libpri/ \
		ftp://ftp.digium.com/pub/libpri/old/

PKGNAMESUFFIX=	-bristuff
PATCHFILES=	${PORTNAME}-${PORTVERSION}-${BRIVER}.patch.gz
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	fjoe
PATCH_DIST_STRIP=	-p1
BRIVER=		bristuff-0.3.0-PRE-1s

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A C implementation of the Primary Rate ISDN specification

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

.include <bsd.port.post.mk>
