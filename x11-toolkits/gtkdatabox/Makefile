# ex:ts=8
# Ports collection makefile for:	gtkdatabox
# Date created:			Mar 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkdatabox
PORTVERSION=	0.9.1.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+2 widget to display large amounts of numerical data

LICENSE=	LGPL21

OPTIONS_DEFINE=	GLADE GLADEUI DOCS EXAMPLES
GLADE_DESC=	Enable libglade2 support
GLADEUI_DESC=	Enable glade3 support

USE_GNOME=	gnomehack gtk20
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--includedir="${PREFIX}/include/${PORTNAME}" \
		--with-html-dir="${PREFIX}/share/doc"
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLADE}
USE_GNOME+=	libglade2
CONFIGURE_ARGS+=	--enable-libglade
PLIST_SUB+=	GLADE=""
.else
CONFIGURE_ARGS+=	--disable-libglade
PLIST_SUB+=	GLADE="@comment "
.endif

.if ${PORT_OPTIONS:MGLADEUI}
LIB_DEPENDS+=	gladeui-1:${PORTSDIR}/devel/glade3
CONFIGURE_ARGS+=	--enable-glade
PLIST_SUB+=	GLADEUI=""
.else
CONFIGURE_ARGS+=	--disable-glade
PLIST_SUB+=	GLADEUI="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIR/s|examples||' ${WRKSRC}/Makefile.in
.for dir in examples gtk
	@${REINPLACE_CMD} -e \
		'/-O2/d ; \
		 /DISABLE_DEPRECATED/d' ${WRKSRC}/${dir}/Makefile.in
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/reference/html/*.* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
