# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/print/libgnomeprint/Makefile,v 1.77 2010/09/28 16:38:29 kwm Exp $

PORTNAME=	libgnomeprint
PORTVERSION=	2.18.8
PORTREVISION=	1
CATEGORIES=	print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome print support library

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libpopt.so:${PORTSDIR}/devel/popt

USES=		bison pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix intlhack gnomehier glib20 pango libxml2 \
		libartlgpl2 ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=${PORTVERSION} \
		LIBVERSION=2.2

OPTIONS_DEFINE=	CUPS
OPTIONS_DEFAULT=CUPS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
CONFIGURE_ARGS+=	--with-cups
LIB_DEPENDS+=		libgnomecups-1.0.so:${PORTSDIR}/print/libgnomecups
PLIST_SUB+=		CUPS:=""
.else
CONFIGURE_ARGS+=	--without-cups
PLIST_SUB+=		CUPS:="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc[.]h>|<stdlib.h>|'
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
