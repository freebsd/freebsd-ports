# New ports collection makefile for:   gtk13
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	2.4.7
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME:S,%SUBDIR%,sources/gtk+/2.4,} \
		ftp://ftp.gtk.org/pub/gtk/v2.3/ \
		ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
		http://www.ameth.org/gimp/%SUBDIR%/ \
		ftp://ftp.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gtk/v${PORTVERSION:R}
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome2

.if defined(WITH_DROPSHADOW)
PATCH_SITES=	${MASTER_SITE_SOURCEFORGE}
PATCH_SITE_SUBDIR=	xfce
PATCHFILES=	gtk+-2.4.0-menushadow.patch
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI (current stable version)

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info \
		${X11BASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_BZIP2=	yes
LATEST_LINK=	gtk20
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
USE_PERL5=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomehack atk pango
CONFIGURE_ARGS=	--enable-static --with-xinput=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype2 \
			  -I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
PLIST_SUB=	GTK_VERSION="2.4.0"

pre-everything::
.if !defined(WITH_DROPSHADOW)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with experimental menu dropshadow patch,"
	@${ECHO_MSG} "hit Ctrl-C right now and use make \"WITH_DROPSHADOW=yes\""
	@${ECHO_MSG} "NOTE: This option is not supported by the FreeBSD GNOME Team."
	@${ECHO_MSG} "If the patch does not work or causes the build to fail, just"
	@${ECHO_MSG} "stop using the patch; we will not further debug it."
	@${ECHO_MSG}
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${GREP} -l lgmodule | \
		${XARGS} ${REINPLACE_CMD} -e 's|-lgmodule|@GMODULE_LIBS@|g'
	@${REINPLACE_CMD} -e 's|[{]libdir[}]/locale|{datadir}/locale|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/gtk/xdgmime/xdgmime.c

pre-build:
	@${RM} -rf ${WRKSRC}/docs/gtk.info*

.include <bsd.port.mk>
