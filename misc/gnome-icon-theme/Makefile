# New ports collection makefile for:	gnome-icon-theme
# Date Created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/misc/gnome-icon-theme/Makefile,v 1.74 2006/04/13 07:52:36 bland Exp $
#

PORTNAME=	gnome-icon-theme
PORTVERSION=	2.14.2
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of icons for the GNOME 2 desktop

BUILD_DEPENDS=	${X11BASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme
RUN_DEPENDS=	${X11BASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack intlhack gnometarget gtk20
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g ; \
		s|[(]datadir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|@mkdir_p@|mkdir -p|g' \
		${WRKSRC}/po/Makefile.in.in

post-install:
	@${MKDIR} ${PREFIX}/share/icons/gnome/48x48/apps

.include <bsd.port.mk>
