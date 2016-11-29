# Created by: Glenn Trewitt <glenn@trewitt.org>
# $FreeBSD$

PORTNAME=	htmldoc
PORTVERSION=	1.8.28
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.msweet.org/files/project1/ \
		EASYSW/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	jose@diasfernandes.pt
COMMENT=	Converts HTML to PDF and/or PostScript

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

OPTIONS_DEFINE=	HTMLDOCGUI
HTMLDOCGUI_DESC=	Build GUI front-end

USES=		jpeg tar:bzip2
USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
# Configure seems broken and ignores these ATM:
CONFIGURE_ARGS+=--disable-localjpeg --disable-localzlib --disable-localpng
# Explicitely disable gnutls as it fails to build if detected
CONFIGURE_ARGS+=--disable-gnutls
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
EXCLUDE=	png jpeg zlib htmldoc/md5* htmldoc/rc4* htmldoc/snprintf*
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}
INSTALL_TARGET=	install \
		bindir=${STAGEDIR}${PREFIX}/bin \
		datadir=${STAGEDIR}${PREFIX}/share \
		mandir=${STAGEDIR}${MANPREFIX}/man
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib

HTMLDOCGUI_LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk
HTMLDOCGUI_CONFIGURE_ON=	--with-gui=yes
HTMLDOCGUI_CONFIGURE_OFF=	--with-gui=no

post-patch:
	${REINPLACE_CMD} -e 's,@JPEG@ @ZLIB@ @PNG@ ,,' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|@LDFLAGS@|-L${LOCALBASE}/lib @LDFLAGS@|'	\
	    -e 's|@JPEGINC@ @PNGINC@ @ZLIBINC@|-I${LOCALBASE}/include|' \
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

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.include <bsd.port.post.mk>
