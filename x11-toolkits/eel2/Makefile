# New ports collection makefile for:    eel2
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eel2
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	2.0.0/releases/gnome-2.0-desktop-final
DIST_SUBDIR=	gnome2
DISTNAME=	eel-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	gnomevfs-2.0:${PORTSDIR}/devel/gnomevfs2 \
		gailutil.16:${PORTSDIR}/x11-toolkits/gail \
		gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc --enable-shared --enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${REINPLACE_CMD} -e \
		's|[(]datadir[)]/gnome/|(datadir)/|g ; \
		 s|[(]datadir[)]/locale|(prefix)/share/locale|g ; \
		 s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

.include <bsd.port.mk>
