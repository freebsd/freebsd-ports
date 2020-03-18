# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	xawtv
PORTVERSION=	3.106
CATEGORIES=	multimedia
MASTER_SITES=	http://linuxtv.org/downloads/xawtv/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	TV viewing application and a few TV utilities

BUILD_DEPENDS=	${LOCALBASE}/share/fonts/misc/led-iso8859-1.pcf.gz:x11-fonts/tv-fonts
RUN_DEPENDS=	${LOCALBASE}/share/fonts/misc/led-iso8859-1.pcf.gz:x11-fonts/tv-fonts
LIB_DEPENDS=	libpng.so:graphics/png

OPTIONS_DEFINE=		AALIB BKTR DV QUICKTIME ZVBI
OPTIONS_DEFINE_i386=	MMX
OPTIONS_DEFAULT=	AALIB BKTR
.if !exists(/usr/include/dev/bktr/ioctl_bt848.h)
OPTIONS_EXCLUDE=	BKTR
.endif
OPTIONS_SUB=		yes

BKTR_DESC=	bktr(4) support
ZVBI_DESC=	Enable libzvbi support

BKTR_MAKE_ARGS=	HAVE_BKTR=yes

USES=		gmake iconv jpeg motif ncurses perl5 tar:bzip2 pkgconfig xorg
GNU_CONFIGURE=	yes
USE_XORG=	x11 xaw
CPPFLAGS+=	-I${WRKSRC}/common
LIBS+=		-L${LOCALBASE}/lib
MAKE_ENV=	verbose=yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	amd64 i386

FILES_LIBJPEG=	console/Subdir.mk x11/Subdir.mk libng/plugins/Subdir.mk

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAALIB}
CONFIGURE_ARGS+=--enable-aa
LIB_DEPENDS+=	libaa.so:graphics/aalib
.else
CONFIGURE_ARGS+=--disable-aa
.endif

.if ${PORT_OPTIONS:MZVBI}
LIB_DEPENDS+=	libzvbi.so:devel/libzvbi
CONFIGURE_ARGS+=--enable-zvbi
.else
CONFIGURE_ARGS+=--enable-zvbi=no
.endif

.if ${PORT_OPTIONS:MDV}
LIB_DEPENDS+=	libdv.so:multimedia/libdv
CONFIGURE_ARGS+=--enable-dv
.else
CONFIGURE_ARGS+=--enable-dv=no
.endif

.if ${PORT_OPTIONS:MMMX}
CONFIGURE_ARGS+=--enable-mmx
CFLAGS+=	-DMMX=1
.endif

.if ${PORT_OPTIONS:MQUICKTIME}
CONFIGURE_ARGS+=--enable-quicktime
LIB_DEPENDS+=	libquicktime.so:multimedia/libquicktime
.else
CONFIGURE_ARGS+=--enable-quicktime=no
.endif

PLIST_SUB+=	X11PREFIX=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g; \
		s|/usr/local|${LOCALBASE}|g; \
		s|-lquicktime|-L${LOCALBASE}/lib &|g; \
		s|LIBV4L="yes"|LIBV4L="no"|g; \
		s|-lunicode|-liconv &|g' \
		${WRKSRC}/configure

	@${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/console/Subdir.mk \
		${WRKSRC}/x11/Subdir.mk

	@${REINPLACE_CMD} -e 's|linuxyesyes|bsdyesyes|g' \
		${WRKSRC}/x11/Subdir.mk

	@${REINPLACE_CMD} -e 's|\(@CFLAGS@.*\)\$$(LIB_FLAGS) |\$$(LIB_FLAGS) \1|g; \
		s|-Llibng||g' \
		${WRKSRC}/Makefile.in

.for i in ${FILES_LIBJPEG}
	@${REINPLACE_CMD} -e "s|-ljpeg|-L${LOCALBASE}/lib -ljpeg|g" ${WRKSRC}/$i
.endfor

.include <bsd.port.post.mk>
