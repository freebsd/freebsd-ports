# New ports collection makefile for:	guppi
# Date created:				22 December 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guppi
PORTVERSION=	0.40.3
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/Guppi
DISTNAME=	Guppi-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	gnumeric:${PORTSDIR}/math/gnumeric
LIB_DEPENDS=	guile.9:${PORTSDIR}/lang/guile
RUN_DEPENDS=	gnumeric:${PORTSDIR}/math/gnumeric

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_PYTHON=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-explicit-python-linking
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include/libglade-1.0" \
		LIBS="-L${LOCALBASE}/lib -pthread"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
PLIST_SUB=	VERSION="${PORTVERSION}"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
