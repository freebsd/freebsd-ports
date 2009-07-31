# New ports collection makefile for:	gnome-icon-theme
# Date Created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/misc/gnome-icon-theme/Makefile,v 1.129 2009/03/21 04:24:51 marcus Exp $
#

PORTNAME=	gnome-icon-theme
PORTVERSION=	2.26.0
PORTREVISION=	2
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of icons for the GNOME 2 desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		icon-naming-utils>=0.8.1:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack intlhack gtk20
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|@mkdir_p@|mkdir -p|g' \
		${WRKSRC}/po/Makefile.in.in

post-install:
	@${MKDIR} ${PREFIX}/share/icons/gnome/48x48/apps

.include <bsd.port.mk>
