# New ports collection makefile for:		geg
# Date created:					8 Aug 1998
# Whom:						rom
#
# $FreeBSD$
#

PORTNAME=	geg
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.infolaunch.com/~daveb/
MASTER_SITE_SUBDIR=	science/visualization/plotting

MAINTAINER=	domi@saargate.de
COMMENT=	Visualise multiple 2D-functions of one variable

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213
AUTOMAKE_ARGS=	-a -i
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		geg.1
PLIST_FILES=	bin/geg

pre-configure:
	@cd ${WRKSRC}; ${ACLOCAL} -I ${X11BASE}/share/aclocal

.include <bsd.port.mk>
