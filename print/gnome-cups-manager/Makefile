# New ports collection makefile for:	gnome-cups-manager
# Date created:				14 Jul 2003
# Whom:					Glenn Johnson <glennpj@charter.net>
#
# $FreeBSD$

PORTNAME=	gnome-cups-manager
PORTVERSION=	0.19
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.19
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Admistration tool for cups

LIB_DEPENDS=	gnomecups-1.0.1:${PORTSDIR}/print/libgnomecups

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeprintui libgnomeui
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		< ${FILESDIR}/gnome-cups-manager.desktop \
		> ${WRKSRC}/gnome-cups-manager.desktop
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		"s|-D.*_DISABLE_DEPRECATED||g"

post-install:
	${INSTALL_DATA} ${WRKSRC}/gnome-cups-manager.desktop \
		${PREFIX}/share/gnome/applications

.include <bsd.port.mk>
