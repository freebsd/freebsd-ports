# New ports collection makefile for:	blt
# Date created:		22 September 1998
# Whom:			Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $FreeBSD$
#

PORTNAME=	blt
PORTVERSION=	2.4z
CATEGORIES=	x11-toolkits tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.csl.sony.co.jp/pub/kjc/ttt-libs/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	BLT${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/${PORTNAME}/} \
		ftp://ftp.csl.sony.co.jp/pub/kjc/ttt-libs/
PATCHFILES=	blt2.4z-patch-2
PATCH_DIST_STRIP= -p1

MAINTAINER=	kjc@iijlab.net
COMMENT=	A Tk extension (with shared libs)

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/blt2.4z
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--exec_prefix=${PREFIX} \
		--with-tcl=${LOCALBASE}/lib/tcl${TK_VER} \
		--with-tk=${LOCALBASE}/lib/tk${TK_VER} \
		--with-tcllibs=${LOCALBASE}/lib/ \
		--with-tklibs=${LOCALBASE}/lib/ \
		--with-tclincls=${LOCALBASE}/include/tcl${TK_VER} \
		--with-tkincls=${LOCALBASE}/include/tk${TK_VER}
INSTALLS_SHLIB=	yes

TK_VER?=	8.4

.include <bsd.port.pre.mk>

post-install:
	${LN} -sf libBLT24.so.3 ${PREFIX}/lib/libBLT24.so
	${LN} -sf libBLTlite24.so.3 ${PREFIX}/lib/libBLTlite24.so

.include <bsd.port.post.mk>
