# New ports collection makefile for:	gnome-cups-manager
# Date created:				14 Jul 2003
# Whom:					Glenn Johnson <glennpj@charter.net>
#
# $FreeBSD$
#

PORTNAME=	gnome-cups-manager
PORTVERSION=	0.31
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Admistration tool for cups

LIB_DEPENDS=	gnomecups-1.0.1:${PORTSDIR}/print/libgnomecups
RUN_DEPENDS=	gnomesu:${PORTSDIR}/security/libgnomesu

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeprintui libgnomeui \
		desktopfileutils
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		< ${FILESDIR}/gnome-cups-manager.desktop \
		> ${WRKSRC}/gnome-cups-manager.desktop
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

post-install:
	${MKDIR} ${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/gnome-cups-manager.desktop \
		${PREFIX}/share/gnome/applications

.include <bsd.port.mk>
