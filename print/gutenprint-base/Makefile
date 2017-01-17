# Created by: dgilbert@velocet.ca
# $FreeBSD$
#    $MCom: ports/print/gutenprint-base/Makefile,v 1.8 2007/03/30 16:45:02 ahze Exp $

PORTNAME?=	gutenprint
PORTVERSION=	5.2.10
PORTREVISION?=	2
CATEGORIES=	print
MASTER_SITES=	SF/gimp-print/gutenprint-5.2/${PORTVERSION}
PKGNAMESUFFIX?=	-base

MAINTAINER=	cmt@burggraben.net
COMMENT=	GutenPrint Printer Driver

LICENSE=	GPLv2

CONFLICTS=	gimp-print-[0-9]*

.if !defined(GUT_SLAVE)
OPTIONS_DEFINE=	GTK2
OPTIONS_DEFAULT=GTK2
OPTIONS_SUB=	yes
.endif

GTK2_CONFIGURE_ENABLE=	libgutenprintui2
GTK2_LIB_DEPENDS=	libgtk-x11-2.0.so:x11-toolkits/gtk20

.include <bsd.port.options.mk>

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-gimp --without-gimp2
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${PREFIX}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${PREFIX}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${SLAVE_PORT}=="yes"
LIB_DEPENDS+=	libgutenprint.so:print/gutenprint-base
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
GUTENPRINTUI2_LIBS=`${PKG_CONFIG} --libs gutenprintui2`
.endif

.if defined(GUT_SLAVE) && ${GUT_SLAVE}=="gimp"
LIB_DEPENDS+=	libgimp-2.0.so:graphics/gimp-app
CONFIGURE_ARGS+=--with-gimp2=yes # Override CONFIGURE_ARGS
BUILD_WRKSRC=	${WRKSRC}/src/gimp2
INSTALL_WRKSRC=	${WRKSRC}/src/gimp2
.endif

.if defined(GUT_SLAVE) && ${GUT_SLAVE}=="cups"
# XXX: check for DragonFly
PLIST_FILES+=	libexec/cups/backend/gutenprint52+usb \
		share/cups/usb/net.sf.gimp-print.usb-quirks
LIB_DEPENDS+=	libcupsimage.so:print/cups
RUN_DEPENDS+=	${LOCALBASE}/libexec/cups/filter/gstoraster:print/cups-filters
CONFIGURE_ARGS+=	--with-cups=${PREFIX} \
			--enable-cups-ppds \
			--enable-cups-level3-ppds
BUILD_WRKSRC=	${WRKSRC}/src/cups
INSTALL_WRKSRC=	${WRKSRC}/src/cups
.else
CONFIGURE_ARGS+=	--without-cups
.endif

.if defined(GUT_SLAVE) && ${GUT_SLAVE}=="ijs"
LIB_DEPENDS+=	libijs.so:print/libijs
CONFIGURE_ARGS+=--with-ijs=yes
BUILD_WRKSRC=	${WRKSRC}/src/ghost
INSTALL_WRKSRC=	${WRKSRC}/src/ghost
.else
CONFIGURE_ARGS+=--without-ghostscript
.endif

.if defined(GUT_SLAVE) && ${GUT_SLAVE}=="foomatic"
BUILD_DEPENDS+=	foomatic-combo-xml:print/foomatic-db-engine
RUN_DEPENDS+=	foomatic-combo-xml:print/foomatic-db-engine \
		${LOCALBASE}/share/cups/model/foomatic-db-ppds:print/foomatic-db
CONFIGURE_ARGS+=--with-foomatic=yes --with-foomatic3=yes
BUILD_WRKSRC=	${WRKSRC}/src/foomatic
INSTALL_WRKSRC=	${WRKSRC}/src/foomatic
.else
CONFIGURE_ARGS+=--without-foomatic
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/lpstat|${LOCALBASE}/bin/lpstat|' \
		${WRKSRC}/src/gutenprintui2/plist.c
.if ${SLAVE_PORT}=="no" || ${GUT_SLAVE}!="cups"
	@${REINPLACE_CMD} -e 's|cups	||' ${WRKSRC}/src/Makefile.in
.endif
.if ${SLAVE_PORT}=="yes"
	@${REINPLACE_CMD} -e 's|= escputil.1|= |' ${WRKSRC}/man/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|%%GUTENPRINTUI2_LIBS%%|${GUTENPRINTUI2_LIBS}|' \
		${WRKSRC}/src/gimp2/Makefile.in
	@${REINPLACE_CMD} -e 's|$$libdir/gimp/1.2/plug-ins||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|= $$(pkglibdir)|= ${PREFIX}/libexec/cups|' \
		${WRKSRC}/src/cups/Makefile.in

pre-configure:
.if defined(GUT_SLAVE) && (${GUT_SLAVE}=="gimp")
	@test -f ${LOCALBASE}/lib/libgutenprintui2.so || (printf "\nprint/gutenprint-base must be rebuilt with GTK2 support\n\n" && exit 1)
.endif

pre-build:
.if defined(GUT_SLAVE) && (${GUT_SLAVE}=="foomatic" || ${GUT_SLAVE}=="cups")
	@(cd ${WRKSRC}/src/xml && ${MAKE})
.endif

pre-install:
.if !defined(GUT_SLAVE)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gutenprint/5.2/modules
.endif

post-install:
.if ${SLAVE_PORT}=="yes"
	@(cd ${WRKSRC}/man && ${GMAKE} ${INSTALL_TARGET} DESTDIR=${STAGEDIR})
.endif
.if defined(GUT_SLAVE) && ${GUT_SLAVE}=="cups"
	@${LN} -s ${LOCALBASE}/sbin/cups-genppd.5.2 \
		${STAGEDIR}${LOCALBASE}/sbin/cups-genppd
.endif

.include <bsd.port.post.mk>
