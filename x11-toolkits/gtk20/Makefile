# New ports collection makefile for:   gtk13
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	2.0.7
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME:S,%SUBDIR%,sources/gtk+/2.0,} \
		ftp://ftp.gtk.org/pub/gtk/v2.0/ \
		ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
		http://www.ameth.org/gimp/%SUBDIR%/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gtk/v${PORTVERSION:R}
DISTNAME=	gtk+-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	atk-1.0.0:${PORTSDIR}/devel/atk \
		pango-1.0.0:${PORTSDIR}/x11-toolkits/pango \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
NO_LATEST_LINK=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
USE_PERL5=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype2 \
			  -I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
PLIST_SUB=	GTK_VERSION="2.0.0"

MAN1=		gdk-pixbuf-csource.1

.if defined(WITH_XINPUT)
CONFIGURE_ARGS+=	--with-xinput=xfree
.endif

post-extract:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${GREP} -l lgmodule | \
		xargs ${REINPLACE_CMD} -e 's|-lgmodule|@GMODULE_LIBS@|g'

pre-build:
	${RM} -rf ${WRKSRC}/docs/gtk.info*

.include <bsd.port.mk>
