# New ports collection makefile for:	fox
# Date created:		23 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION=	0.99.166
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.cfdrc.com/pub/FOX/ \
		ftp://SunSITE.Informatik.RWTH-Aachen.DE/pub/Linux/fox/

MAINTAINER?=	knu@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png

.if defined(WITH_XUNICODE)
PKGNAMESUFFIX=	-xunicode

PATCH_SITES=	http://www.ab.wakwak.com/~tino/jatk/fox/
PATCHFILES=	${PORTNAME}${PKGNAMESUFFIX}-${PATCHVERSION}.diff
PATCH_DIST_STRIP=	-p1

BUILD_DEPENDS=	${X11BASE}/include/xunicode/xunicode.h:${PORTSDIR}/converters/xunicode

CONFIGURE_ENV=	X_CFLAGS=-DUSE_XUNICODE
.endif

PATCHVERSION=	${PORTVERSION}

USE_MESA=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=--with-opengl=mesa --with-x
.if defined(NO_SHM)
CONFIGURE_ARGS+=--with-shm=no
.else
CONFIGURE_ARGS+=--with-shm=yes
.endif
.if defined(DEBUG)
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--enable-release
.endif
.if defined(WANT_PROFILE)
CONFIGURE_ARGS+=--with-profiling=gprof
.endif
USE_LIBTOOL=	yes
SHLIB_MAJ=	1
SHLIB_MIN=	0
MAKE_ENV+=	LT_CURRENT="${SHLIB_MAJ}" LT_REVISION="${SHLIB_MIN}"
PLIST_SUB+=	LIBVER="${SHLIB_MAJ}"
MAN1=		reswrap.1

.if defined(WITH_XUNICODE)
post-extract:
	cd ${WRKSRC} && ${LN} -s ${X11BASE}/include/xunicode
.endif

.include <bsd.port.mk>
