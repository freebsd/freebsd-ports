# Created by: Kenjiro Cho <kjc@csl.sony.co.jp>
# $FreeBSD$

PORTNAME=	blt
PORTVERSION=	2.4z
PORTREVISION=	7
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/${PORTNAME}/BLT/BLT%20${PORTVERSION} \
		ftp://ftp.csl.sony.co.jp/pub/kjc/ttt-libs/
DISTNAME=	BLT${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE:C/%SUBDIR%/${PORTNAME}\/BLT\/BLT%20${PORTVERSION}/} \
		ftp://ftp.csl.sony.co.jp/pub/kjc/ttt-libs/
PATCH_SITE_SUBDIR=	${PORTNAME}
PATCHFILES=	blt2.4z-patch-2
PATCH_DIST_STRIP=-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extension for the Tk toolkit (with shared libs)

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

WRKSRC=		${WRKDIR}/blt2.4z
GNU_CONFIGURE=	yes
CFLAGS+=	-Wall -Wno-uninitialized
CFLAGS+=	-I${TK_INCLUDEDIR}/generic -I${TK_INCLUDEDIR}/unix

USES+=		tk:84,85
USE_XORG=	x11

post-patch:
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
	    ${REINPLACE_CMD} -e '/^INSTALL_ROOT/s|$$|$${DESTDIR}|'

post-install:
	${LN} -sf libBLT24.so.3 ${STAGEDIR}${PREFIX}/lib/libBLT24.so
	${LN} -sf libBLTlite24.so.3 ${STAGEDIR}${PREFIX}/lib/libBLTlite24.so

CONFIGURE_ARGS+=--exec_prefix=${PREFIX} \
		--enable-jpeg=${LOCALBASE} \
		--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--with-tcllibs=${LOCALBASE}/lib/ \
		--with-tklibs=${LOCALBASE}/lib/ \
		--with-tclincls=${TCL_INCLUDEDIR} \
		--with-tkincls=${TK_INCLUDEDIR}

.include <bsd.port.mk>
