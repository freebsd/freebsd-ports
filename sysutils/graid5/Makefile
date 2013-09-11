# New ports collection makefile for:	graid5
# Date created:				09 Nov 2010
# Whom:					Lev Serebryakov <lev@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	graid5
PORTVERSION=	${MAINVERSION}.${VERSIONDATE}
PORTREVISION=	2
CATEGORIES=	sysutils kld
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/graid5/

MAINTAINER=	lev@FreeBSD.org
COMMENT=	RAID5 geom class

USE_BZIP2=	yes

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

MAINVERSION=1.1
VERSIONDATE=20130907.44

KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR:C,^/,,}
SUB_LIST=	KMODDIR=${KMODDIR}
SUB_FILES=	pkg-deinstall
MAKE_ENV+=	KMODDIR=${KMODDIR} SRC_BASE=${SRC_BASE}

.if defined(SYSDIR)
MAKE_ENV+=	SYSDIR=${SYSDIR}
.endif

MANCOMPRESSED=	yes
MAN8=		${PORTNAME}.8

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files
.elif !exists(${SRC_BASE}/sbin/geom/Makefile)
IGNORE=	requires sbin source files
.endif

post-install:
	kldxref ${KMODDIR}

.include <bsd.port.post.mk>
