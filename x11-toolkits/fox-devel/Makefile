# New ports collection makefile for:	fox
# Date created:		23 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	fox
PORTVERSION= 	0.99.122
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.cfdrc.com/pub/FOX/ \
		ftp://imssun1.epfl.ch/pub/sources/ \
		ftp://SunSITE.Informatik.RWTH-Aachen.DE/pub/Linux/fox/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		GL.14:${PORTSDIR}/graphics/Mesa3

INSTALLS_SHLIB=	yes
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
PLIST_SUB+=	LIBVER="${SHLIB_MAJ}"
MAN1=		reswrap.1

.include <bsd.port.mk>
