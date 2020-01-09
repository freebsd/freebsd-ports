# Created by: Lev Serebryakov <lev@FreeBSD.org>
# $FreeBSD$

PORTNAME=	graid5
PORTVERSION=	${MAINVERSION}.${VERSIONDATE}
CATEGORIES=	sysutils
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/graid5/

MAINTAINER=	lev@FreeBSD.org
COMMENT=	RAID5 geom class

LICENSE=	BSD2CLAUSE

MAINVERSION=1.3
VERSIONDATE=20140711.62

MAKE_ENV+=	KMODDIR=${KMODDIR} SRC_BASE=${SRC_BASE}

USES=		tar:bzip2 kmod uidfix

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sbin/geom/Makefile)
IGNORE=	requires sbin source files
.endif

pre-install:
	${MKDIR} ${STAGEDIR}/lib/geom
	${MKDIR} ${STAGEDIR}/sbin

.include <bsd.port.post.mk>
