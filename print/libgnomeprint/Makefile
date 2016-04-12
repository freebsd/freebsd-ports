# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/print/libgnomeprint/Makefile,v 1.77 2010/09/28 16:38:29 kwm Exp $

PORTNAME=	libgnomeprint
PORTVERSION=	2.18.8
PORTREVISION=	4
CATEGORIES=	print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome print support library

USES=		tar:bzip2

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

GNU_CONFIGURE=	yes
USES+=		bison gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack glib20 pango libxml2 libartlgpl2
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=${PORTVERSION} \
		LIBVERSION=2.2

OPTIONS_DEFINE=	CUPS
OPTIONS_DEFAULT=CUPS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
CONFIGURE_ARGS+=	--with-cups
LIB_DEPENDS+=		libgnomecups-1.0.so:print/libgnomecups
PLIST_SUB+=		CUPS:=""
.else
CONFIGURE_ARGS+=	--without-cups
PLIST_SUB+=		CUPS:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|doc||" ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts
	@${TOUCH} ${STAGEDIR}${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts/gnome-print.fontmap
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnomeprint-2-2.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnomeprint/2.18.8/modules/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnomeprint/2.18.8/modules/*/*.so

.include <bsd.port.mk>

.endif
