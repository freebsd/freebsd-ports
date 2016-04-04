# Created by: Glenn Johnson <glennpj@charter.net>
# $FreeBSD$
#   $MCom: ports/print/gnome-cups-manager/Makefile,v 1.8 2007/07/20 01:11:31 mezz Exp $

PORTNAME=	gnome-cups-manager
PORTVERSION=	0.31
PORTREVISION=	16
PORTEPOCH=	1
CATEGORIES=	print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Administration tool for cups

LIB_DEPENDS=	libgnomecups-1.0.so:print/libgnomecups
RUN_DEPENDS=	gnomesu:security/libgnomesu

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix intlhack libgnomeprintui libgnomeui
USE_LDCONFIG=	yes
USE_XORG=	x11
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -D_IPP_PRIVATE_STRUCTURES
LIBS+=		-L${LOCALBASE}/lib

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		< ${FILESDIR}/gnome-cups-manager.desktop \
		> ${WRKSRC}/gnome-cups-manager.desktop
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'
	@${REINPLACE_CMD} '/^gnome_cups_icon_LDADD =/s/$$/ -lX11/' \
		${WRKSRC}/gnome-cups-manager/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/libgnomecups/gnome-cups-ui-driver.c
	@${REINPLACE_CMD} -e 's|glib/gmacros.h>|glib.h>|g' \
			-e 's|glib/gstrfuncs.h>|glib.h>|g' \
		${WRKSRC}/libgnomecups/gnome-cups-ui-init.h \
		${WRKSRC}/libgnomecups/gnome-cups-ui-print.h \
		${WRKSRC}/libgnomecups/gnome-cups-i18n.c \
		${WRKSRC}/libgnomecups/gnome-cups-ui-driver.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/gnome-cups-manager.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
