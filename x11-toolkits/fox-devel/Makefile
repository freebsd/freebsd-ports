# New ports collection makefile for:	fox
# Date created:		23 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION= 	0.99.112
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.cfdrc.com/pub/FOX/ \
		ftp://imssun1.epfl.ch/pub/ \
		ftp://SunSITE.Informatik.RWTH-Aachen.DE/pub/Linux/fox/
DISTNAME=	${PORTNAME}

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		GL.14:${PORTSDIR}/graphics/Mesa3

GNU_CONFIGURE=	yes
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
WRKSRC=		${WRKDIR}/${PKGNAME}
SHLIB_MAJ=	1
SHLIB_MIN=	0
MAKE_ENV+=	LT_CURRENT="${SHLIB_MAJ}" LT_REVISION="${SHLIB_MIN}"
MAN1=		reswrap.1

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
PLIST_SUB+=	LIBVER="${SHLIB_MAJ}"
.else
PLIST_SUB+=	LIBVER="${SHLIB_MAJ}.${SHLIB_MIN}"
.endif

.include <bsd.port.post.mk>
