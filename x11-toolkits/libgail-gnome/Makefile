# New ports collection makefile for:   libgail-gnome
# Date Created:			12 April 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgail-gnome
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.1
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An implementation of the ATK interfaces for GNOME widgets

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack gnomepanel atspi
CONFIGURE_ARGS=	--enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/test//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	does not build on 4.X
.endif

.include <bsd.port.post.mk>
