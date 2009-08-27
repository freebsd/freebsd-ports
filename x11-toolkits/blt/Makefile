# New ports collection makefile for:	blt
# Date created:		22 September 1998
# Whom:			Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $FreeBSD$
#

PORTNAME=	blt
PORTVERSION=	2.4z
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/${PORTNAME}/BLT/BLT%20${PORTVERSION} \
		ftp://ftp.csl.sony.co.jp/pub/kjc/ttt-libs/

DISTNAME=	BLT${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE:C/%SUBDIR%/${PORTNAME}\/BLT\/BLT%20${PORTVERSION}/} \
		ftp://ftp.csl.sony.co.jp/pub/kjc/ttt-libs/
PATCH_SITE_SUBDIR=	${PORTNAME}
PATCHFILES=	blt2.4z-patch-2
PATCH_DIST_STRIP= -p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tk extension (with shared libs)

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22

WRKSRC=		${WRKDIR}/blt2.4z
GNU_CONFIGURE=	yes

USE_TK=		82+
INVALID_TK_VER=	85 86
USE_XORG=	x11

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--exec_prefix=${PREFIX} \
		--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--with-tcllibs=${LOCALBASE}/lib/ \
		--with-tklibs=${LOCALBASE}/lib/ \
		--with-tclincls=${TCL_INCLUDEDIR} \
		--with-tkincls=${TK_INCLUDEDIR}

post-install:
	${LN} -sf libBLT24.so.3 ${PREFIX}/lib/libBLT24.so
	${LN} -sf libBLTlite24.so.3 ${PREFIX}/lib/libBLTlite24.so

.include <bsd.port.post.mk>
