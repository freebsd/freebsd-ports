# ex:ts=8
# Ports collection makefile for:	gtkdatabox
# Date created:			Mar 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkdatabox
PORTVERSION=	0.9.0.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF http://www.eudoxos.de/gtk/gtkdatabox/download/
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+2 widget to display large amounts of numerical data

USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gtk20
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS+=	--includedir="${PREFIX}/include/${PORTNAME}" \
			--with-html-dir="${PREFIX}/share/doc"

OPTIONS_DEFINE= GLADE GLADEUI DOCS EXAMPLES
GLADE_DESC=	Enable libglade2 support
GLADEUI_DESC=	Enable glade3 support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_GNOME+=	referencehack
.endif

.if ${PORT_OPTIONS:MGLADE}
USE_GNOME+=	libglade2
CONFIGURE_ARGS+=	--enable-libglade
PLIST_SUB+=	GLADE=""
.else
CONFIGURE_ARGS+=	--disable-libglade
PLIST_SUB+=	GLADE="@comment "
.endif

.if ${PORT_OPTIONS:MGLADEUI}
LIB_DEPENDS+=	gladeui-1.10:${PORTSDIR}/devel/glade3
CONFIGURE_ARGS+=	--enable-glade
PLIST_SUB+=	GLADEUI=""
.else
CONFIGURE_ARGS+=	--disable-glade
PLIST_SUB+=	GLADEUI="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@libglade_moduledir@|@prefix@/lib/libglade/2.0|g ; \
		 s|@glade_moduledir@|@prefix@/lib/glade3/modules|g ; \
		 s|@glade_catalogdir@|@prefix@/share/glade3/catalogs|g'
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/gtk/Makefile.in ${WRKSRC}/examples/Makefile.in

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
