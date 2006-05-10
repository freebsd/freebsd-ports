# New ports collection makefile for:	libgnomeprint
# Date created:				15 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/print/libgnomeprint/Makefile,v 1.54 2005/09/26 21:07:03 marcus Exp $
#

PORTNAME=	libgnomeprint
PORTVERSION=	2.12.1
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.12
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome print support library

USE_BZIP2=	yes
PREFIX?=	${X11BASE}

.if !defined(REFERENCE_PORT)

PORTREVISION=	2

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		popt.0:${PORTSDIR}/devel/popt

USE_BISON=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomehier glib20 pango libxml2 \
		libartlgpl2 ltverhack
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=  libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION} \
		LIBVERSION=2.2

.include <bsd.port.pre.mk>

.if defined(WITH_CUPS) || exists(${LOCALBASE}/lib/libcups.so)
CONFIGURE_ARGS+=	--with-cups
LIB_DEPENDS+=		gnomecups-1.0:${PORTSDIR}/print/libgnomecups
PLIST_SUB+=		CUPS:=""
.else
CONFIGURE_ARGS+=	--without-cups
PLIST_SUB+=		CUPS:="@comment "
.endif

pre-everything::
.if !defined(WITH_CUPS)
	@${ECHO_MSG} " Enable cups support by defining"
	@${ECHO_MSG} " WITH_CUPS"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc[.]h>|<stdlib.h>|'
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|doc||" ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts
	@${TOUCH} ${PREFIX}/etc/gnome/libgnomeprint-2.0/fonts/gnome-print.fontmap

.include <bsd.port.post.mk>

.endif
