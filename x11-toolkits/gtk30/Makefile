# New ports collection makefile for:   gtk13
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	1.3.12
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/gimp/%SUBDIR%/ \
		http://www.ameth.org/gimp/%SUBDIR%/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gtk/v${PORTVERSION:R}
DISTNAME=	gtk+-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	glib-1.3.12:${PORTSDIR}/devel/glib13 \
		atk.9:${PORTSDIR}/devel/atk \
		pango.0:${PORTSDIR}/x11-toolkits/pango \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

NO_LATEST_LINK=	"Unstable, development version."
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_PERL5=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
PLIST_SUB=	GTK_VERSION="${PORTVERSION}"

MAN1=		gdk-pixbuf-csource.1

post-extract:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${GREP} -l lgmodule | \
		xargs ${PERL} -pi -e 's|-lgmodule|\@GMODULE_LIBS\@|g'
	@find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		's|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g'

pre-build:
	${RM} -rf ${WRKSRC}/docs/gtk.info*

.include <bsd.port.mk>
