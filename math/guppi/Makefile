# New ports collection makefile for:	guppi
# Date created:				22 December 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guppi
PORTVERSION=	0.40.3
PORTREVISION=	4
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/Guppi/0.40
DISTNAME=	Guppi-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A plotting program for GNOME

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs bonobo libglade gal gnometarget
USE_PYTHON=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gnumeric --enable-explicit-python-linking
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include/libglade-1.0" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		GNUMERIC_IDLDIR="${WRKDIR}/gnumeric"
PLIST_SUB=	VERSION="${PORTVERSION}"

post-extract:
	@${MKDIR} ${WRKDIR}/gnumeric
	@${CP} ${FILESDIR}/GNOME_Gnumeric_Graph.idl ${WRKDIR}/gnumeric

.include <bsd.port.mk>
