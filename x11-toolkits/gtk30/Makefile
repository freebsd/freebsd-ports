# New ports collection makefile for:   gtk13
# Date Created:			28 Sep 1997
# Whom:				Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	gtk
PORTVERSION=	1.3.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.3/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.3/ \
		http://www.ameth.org/gimp/gtk/v1.3/
DISTNAME=	gtk+-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	glib-1.3.1:${PORTSDIR}/devel/glib13 \
		pango.0:${PORTSDIR}/x11-toolkits/pango \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		intl.1:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gtk-config-2.0.1

post-extract:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${GREP} -l lgmodule | \
		xargs ${PERL} -pi -e 's|-lgmodule|\@GMODULE_LIBS\@|g'

pre-build:
	${RM} -rf ${WRKSRC}/docs/gtk.info*

.include <bsd.port.mk>
