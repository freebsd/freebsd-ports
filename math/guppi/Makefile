# New ports collection makefile for:	guppi
# Date created:				22 December 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guppi
PORTVERSION=	0.40.3
PORTREVISION=	2
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/Guppi/0.40
DISTNAME=	Guppi-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	guile.10:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs bonobo libglade gal
USE_PYTHON=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-explicit-python-linking
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include/libglade-1.0" \
		LIBS="-L${LOCALBASE}/lib -pthread" \
		GNUMERIC_IDLDIR="`cd ${PORTSDIR}/math/gnumeric && ${MAKE} -V WRKSRC`/idl"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
PLIST_SUB=	VERSION="${PORTVERSION}"

# Can't use BUILD_DEPENDS, because then we have `short circuit' for
# make clean - Gnumeric tries to clean-up Guppi, while Guppi in turn
# tries to clean Gnumeric.
post-extract:
	@cd ${PORTSDIR}/math/gnumeric && ${MAKE} patch

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
