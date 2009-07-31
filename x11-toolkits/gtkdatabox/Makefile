# ex:ts=8
# Ports collection makefile for:	gtkdatabox
# Date created:			Mar 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkdatabox
PORTVERSION=	0.9.0.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF http://www.eudoxos.de/gtk/gtkdatabox/download/
DIST_SUBDIR=	gnome2

MAINTAINER=	shuvaev@physik.uni-wuerzburg.de
COMMENT=	A GTK+2 widget to display large amounts of numerical data

USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gtk20
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS+=	--includedir="${PREFIX}/include/${PORTNAME}" \
			--with-html-dir="${PREFIX}/share/doc"

OPTIONS=	GLADE "Enable libglade2 support" off \
		GLADEUI "Enable glade3 support" off

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
USE_GNOME+=	referencehack
.endif

.if !defined(WITHOUT_GLADE)
USE_GNOME+=	libglade2
CONFIGURE_ARGS+=	--enable-libglade
PLIST_SUB+=	GLADE=""
.else
CONFIGURE_ARGS+=	--disable-libglade
PLIST_SUB+=	GLADE="@comment "
.endif

.if !defined(WITHOUT_GLADEUI)
LIB_DEPENDS+=	gladeui-1.7:${PORTSDIR}/devel/glade3
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

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
