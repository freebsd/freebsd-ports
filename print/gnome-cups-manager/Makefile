# Created by: Glenn Johnson <glennpj@charter.net>
# $FreeBSD$
#   $MCom: ports/print/gnome-cups-manager/Makefile,v 1.8 2007/07/20 01:11:31 mezz Exp $

PORTNAME=	gnome-cups-manager
PORTVERSION=	0.31
PORTREVISION=	14
PORTEPOCH=	1
CATEGORIES=	print gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Administration tool for cups

LIB_DEPENDS=	gnomecups-1.0.1:${PORTSDIR}/print/libgnomecups
RUN_DEPENDS=	gnomesu:${PORTSDIR}/security/libgnomesu

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeprintui libgnomeui \
		desktopfileutils
USES=		gettext gmake pkgconfig
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		< ${FILESDIR}/gnome-cups-manager.desktop \
		> ${WRKSRC}/gnome-cups-manager.desktop
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'
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
		${PREFIX}/share/applications

.include <bsd.port.mk>
