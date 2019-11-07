# Created by: Philippe Charnier <charnier@lirmm.fr>
# $FreeBSD$

PORTNAME=	mpeg2codec
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://fossies.org/unix/misc/old/ \
		http://www.imagemagick.org/download/delegates/ \
		http://gd.tuwien.ac.at/graphics/libs/alsolibs/ \
		http://www.mpeg.org/pub_ftp/mpeg/mssg/
DISTNAME=	mpeg2vidcodec_v12

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 Encoder and Decoder

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=	X11

WRKSRC=		${WRKDIR}/mpeg2

USES=		pkgconfig

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

DATADIR=	${PREFIX}/share/mpeg2

CFLAGS+=	-DVERIFY -DVERBOSE -DTRACE

X11_USES=	xorg
X11_USE=	XORG=xext
X11_MAKE_ARGS=	USE_DISP="-DDISPLAY" \
		USE_SHMEM="-DSH_MEM" \
		LIBS="$$(pkg-config --libs xext) -lX11" \
		INCLUDEDIR="$$(pkg-config --cflags xext)"

do-install:
.for i in dec enc
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpeg2${i}/mpeg2${i}ode ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/par/* ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpeg2enc.doc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
