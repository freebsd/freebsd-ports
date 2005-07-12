# New ports collection makefile for:	libpri
# Date created:				25 Oct 2004
# Whom:					Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	libpri
PORTVERSION=	1.0.9
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.asterisk.org/pub/libpri/ \
		ftp://ftp.asterisk.org/pub/libpri/old/

PATCHFILES=	${PORTNAME}-1.0.8-${BRIVER}.patch.gz
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	fjoe
PATCH_DIST_STRIP=	-p1

MAINTAINER=	gonzo@univ.kiev.ua
COMMENT=	A C implementation of the Primary Rate ISDN specification

BRIVER=		bristuff-0.2.0-RC8h
USE_GMAKE=	yes
INSTALLS_SHLIB= yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

.include <bsd.port.post.mk>
