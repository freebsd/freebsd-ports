# New ports collection makefile for:    nautilus
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#

PORTNAME=	nautilus
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/nautilus

MAINTAINER=	ade@FreeBSD.org

BUILD_DEPENDS=	rpm:${PORTSDIR}/misc/rpm
LIB_DEPENDS=	medusa.0:${PORTSDIR}/sysutils/medusa \
		gtkhtml.4:${PORTSDIR}/www/gtkhtml \
		ghttp.1:${PORTSDIR}/www/libghttp \
		bz2.1:${PORTSDIR}/archivers/bzip2

BROKEN=		Build failures with new bonobo"

.if defined(WITH_MOZILLA)
MOZILLA=	mozilla-embedded
BUILD_DEPENDS=	${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}
.endif

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-pthread -L${LOCALBASE}/lib" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz ${MOZILLA_LIBS}"

.if defined(WITH_MOZILLA)
CONFIGURE_ARGS+= --with-mozilla-lib-place=${X11BASE}/lib/${MOZILLA} \
		 --with-mozilla-include-place=${X11BASE}/include/${MOZILLA}
MOZILLA_LIBS=	"-L${X11BASE}/lib/${MOZILLA}"
PLIST_SUB+=	MOZILLA:=""
.else
MOZILLA_LIBS=	""
PLIST_SUB+=	MOZILLA:="@comment "
.endif

.if !defined(WITH_MOZILLA)
pre-extract:
	@${ECHO} "You can add embedded mozilla support by defining WITH_MOZILLA"
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
