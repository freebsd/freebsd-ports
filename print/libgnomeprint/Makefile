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

LIB_DEPENDS=	fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		popt:${PORTSDIR}/devel/popt

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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
CONFIGURE_ARGS+=	--with-cups
LIB_DEPENDS+=		gnomecups-1:${PORTSDIR}/print/libgnomecups
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
	@${MKDIR} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts
	@${TOUCH} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts/gnome-print.fontmap

.include <bsd.port.mk>

.endif
