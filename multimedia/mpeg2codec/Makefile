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

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
MAKE_JOBS_SAFE=	yes

DATADIR=	${PREFIX}/share/mpeg2

CFLAGS+=	-DVERIFY -DVERBOSE -DTRACE

PORTDOCS=	mpeg2enc.doc
PLIST_FILES=	bin/mpeg2decode bin/mpeg2encode \
		%%DATADIR%%/MPEG-1.par %%DATADIR%%/NTSC.par \
		%%DATADIR%%/PAL.par %%DATADIR%%/inter.mat \
		%%DATADIR%%/intra.mat
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	xext
MAKE_ARGS+=	USE_DISP="-DDISPLAY" \
		USE_SHMEM="-DSH_MEM" \
		LIBS="$$(pkg-config --libs xext) -lX11" \
		INCLUDEDIR="$$(pkg-config --cflags xext)"
.endif

do-install:
.for i in dec enc
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpeg2${i}/mpeg2${i}ode ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/par/* ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mpeg2enc.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
