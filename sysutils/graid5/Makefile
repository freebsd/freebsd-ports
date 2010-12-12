# New ports collection makefile for:	graid5
# Date created:				09 Nov 2010
# Whom:					Lev Serebryakov <lev@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	graid5
PORTVERSION=	${MAINVERSION}.${VERSIONDATE}
PORTREVISION=	1	
CATEGORIES=	sysutils kld
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/graid5/

MAINTAINER=	lev@FreeBSD.org
COMMENT=	RAID5 geom class

USE_BZIP2=	yes

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

MAINVERSION=1.0
VERSIONDATE=20101212.29

KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR:C,^/,,}
MAKE_ENV+=	KMODDIR=${KMODDIR}

MANCOMPRESSED=	yes
MAN8=		${PORTNAME}.8

.if !exists(/usr/src/sys/Makefile)
IGNORE=	requires kernel source files
.elif !exists(/usr/src/sbin/geom/Makefile)
IGNORE=	requires sbin source files
.endif

post-install:
	kldxref ${KMODDIR}

post-deinstall:
	kldxref ${KMODDIR}

.include <bsd.port.mk>
