# Created by: Lev Serebryakov <lev@FreeBSD.org>
# $FreeBSD$

PORTNAME=	graid5
PORTVERSION=	${MAINVERSION}.${VERSIONDATE}
CATEGORIES=	sysutils
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/graid5/

MAINTAINER=	lev@FreeBSD.org
COMMENT=	RAID5 geom class

LICENSE=	BSD

USE_BZIP2=	yes

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

MAINVERSION=1.3
VERSIONDATE=20140308.50

KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR:C,^/,,}
MAKE_ENV+=	KMODDIR=${KMODDIR} SRC_BASE=${SRC_BASE}

USES=		kmod uidfix

# It want to make hardlink from /sbin/geom
NO_STAGE=	yes

MANCOMPRESSED=	yes
MAN8=		${PORTNAME}.8

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sbin/geom/Makefile)
IGNORE=	requires sbin source files
.endif

post-install:
	/usr/sbin/kldxref ${KMODDIR}

post-deinstall:
	/usr/sbin/kldxref ${KMODDIR}

.include <bsd.port.post.mk>
