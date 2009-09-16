# New ports collection makefile for:	libpri
# Date created:				25 Oct 2004
# Whom:					Alexander Timoshenko <gonzo@univ.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	libpri
PORTVERSION=	1.4.3
CATEGORIES=	misc
MASTER_SITES=	http://downloads.asterisk.org/pub/telephony/libpri/releases/
PKGNAMESUFFIX=	-bristuff
PATCHFILES=	${PORTNAME}-${PORTVERSION}-${BRIVER}.patch.gz
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	fjoe
PATCH_DIST_STRIP=	-p1
BRIVER=		bristuff-0.4.0-RC3g

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A C implementation of the Primary Rate ISDN specification

USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
