# New ports collection makefile for:   htmldoc
# Date created:        12 June 2001
# Whom:                Glenn Trewitt <glenn@trewitt.org>
#
# $FreeBSD$
#

PORTNAME=	htmldoc
PORTVERSION=	1.8.27
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_EASYSW}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	jose@diasfernandes.pt
COMMENT=	Converts HTML to PDF and/or PostScript

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg	\
		png:${PORTSDIR}/graphics/png

OPTIONS=	HTMLDOCGUI "Build GUI front-end" off
# .bz2 file is available since Aug 2, but we don't want to
# start mirroring _in addition to_ the .gz variant. When the
# vendor's release is updated again, we should switch to .bz2
#USE_BZIP2=	yes

GNU_CONFIGURE=	yes
# Configure seems broken and ignores these ATM:
CONFIGURE_ARGS+=--enable-localjpeg --enable-localzlib --enable-localpng
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
EXCLUDE=	png jpeg zlib htmldoc/md5* htmldoc/rc4* htmldoc/snprintf*
EXTRACT_AFTER_ARGS=| ${TAR} -xf - ${EXCLUDE:S,^,--exclude ,}

MAN1=	htmldoc.1
post-patch:
	${REINPLACE_CMD} -e 's,@JPEG@ @ZLIB@ @PNG@ ,,' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|@LDFLAGS@|-L${LOCALBASE}/lib @LDFLAGS@|'	\
	    -e 's|@JPEGINC@ @PNGINC@ @ZLIBINC@|-I${LOCALBASE}/include|' \
		${WRKSRC}/Makedefs.in
	# Remove redundant code:
	${REINPLACE_CMD} -Ee 's,(md5|snprintf|rc4)\.o,,g'	\
		${WRKSRC}/htmldoc/Makefile

post-configure:
	${REINPLACE_CMD} -e	\
	    's|../png/libpng.a ../zlib/libz.a ../jpeg/libjpeg.a|-ljpeg -lpng -lz|' ${WRKSRC}/Makedefs

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_HTMLDOCGUI)
LIB_DEPENDS+=	fltk:${PORTSDIR}/x11-toolkits/fltk
CONFIGURE_ARGS+=--enable-gui
.else
CONFIGURE_ARGS+=--disable-gui
.endif
.include <bsd.port.post.mk>
