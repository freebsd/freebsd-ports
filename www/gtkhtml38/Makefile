# New ports collection makefile for:	gtkhtml
# Date created:				2nd June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkhtml
PORTVERSION=	1.0.4
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/gtkhtml
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	glibwww.1:${PORTSDIR}/www/glibwww \
		pspell.4:${PORTSDIR}/textproc/pspell \
		gal.19:${PORTSDIR}/x11-toolkits/gal \
		ghttp.1:${PORTSDIR}/www/libghttp

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMECTRL=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-gconf=yes \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${REINPLACE_CMD} -e \
		's|[(]datadir[)]/gnome/|(datadir)/|g ; \
		 s|[(]datadir[)]/locale|(prefix)/share/locale|g'

.include <bsd.port.mk>
