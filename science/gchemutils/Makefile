# New ports collection makefile for:	gchemutils
# Date created:			Mar 18, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	gchemutils
PORTVERSION=	0.1.3
CATEGORIES=	science
MASTER_SITES=	http://savannah.nongnu.org/download/gchemutils/unstable.pkg/${PORTVERSION}/
DISTNAME=	gnome-chemistry-utils-${PORTVERSION}

MAINTAINER=	pav@oook.cz
COMMENT=	C++ classes and Gtk2 widgets related to chemistry

LIB_DEPENDS=	gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix libglade2 libgnomeprint
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
