# New ports collection makefile for:	amcl
# Date created:				15 Apr 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	gnome-mud
PORTVERSION=	0.10.4a
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based MUD client with triggers, aliases, colors, etc

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtk.so:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtk.so:${PORTSDIR}/x11-toolkits/py-gtk2

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack gnometarget libgnomeui vte
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN6=		gnome-mud.6

post-patch:
	@${REINPLACE_CMD} -e \
		's|prefix)/games|prefix)/bin|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
