# Created by: Glenn Trewitt <glenn@trewitt.org>
# $FreeBSD$

PORTNAME=	htmldoc
PORTVERSION=	1.8.28
CATEGORIES=	textproc
MASTER_SITES=	http://www.msweet.org/files/project1/ \
		${MASTER_SITE_EASYSW}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	jose@diasfernandes.pt
COMMENT=	Converts HTML to PDF and/or PostScript

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg	\
		libpng15.so:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	HTMLDOCGUI
HTMLDOCGUI_DESC=	Build GUI front-end

USES=	tar:bzip2

GNU_CONFIGURE=	yes
# Configure seems broken and ignores these ATM:
CONFIGURE_ARGS+=--disable-localjpeg --disable-localzlib --disable-localpng
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
EXCLUDE=	png jpeg zlib htmldoc/md5* htmldoc/rc4* htmldoc/snprintf*
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}
INSTALL_TARGET=	install \
		bindir=${STAGEDIR}${PREFIX}/bin \
		datadir=${STAGEDIR}${PREFIX}/share \
		mandir=${STAGEDIR}${MANPREFIX}/man
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e 's,@JPEG@ @ZLIB@ @PNG@ ,,' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|@LDFLAGS@|-L${LOCALBASE}/lib @LDFLAGS@|'	\
	    -e 's|@JPEGINC@ @PNGINC@ @ZLIBINC@|-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15|' \
		${WRKSRC}/Makedefs.in
	# Remove redundant code:
	${REINPLACE_CMD} -Ee 's,(md5|snprintf|rc4)\.o,,g'	\
		${WRKSRC}/htmldoc/Makefile
	${REINPLACE_CMD} -Ee 's,md5-private\.h,,;s,rc4\.h,,' \
		${WRKSRC}/htmldoc/Dependencies

post-configure:
	${REINPLACE_CMD} -e	\
	    's|../png/libpng.a ../zlib/libz.a ../jpeg/libjpeg.a|-ljpeg -lpng -lz|' ${WRKSRC}/Makedefs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/htmldoc

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHTMLDOCGUI}
LIB_DEPENDS+=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk
CONFIGURE_ARGS+=--with-gui=yes
.else
CONFIGURE_ARGS+=--with-gui=no
.endif
.include <bsd.port.post.mk>
