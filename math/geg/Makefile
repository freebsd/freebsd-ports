# New ports collection makefile for:		geg
# Date created:					8 Aug 1998
# Whom:						rom
#
# $FreeBSD$
#

PORTNAME=	geg
PORTVERSION=	1.0.2
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.infolaunch.com/~daveb/
MASTER_SITE_SUBDIR=	science/visualization/plotting

MAINTAINER=	domi@saargate.de
COMMENT=	Visualise multiple 2D-functions of one variable

USE_GNOME=	gtk12
USE_AUTOTOOLS=	automake:15 autoconf:261
AUTOMAKE_ARGS=	-a -i
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		geg.1
PLIST_FILES=	bin/geg

pre-configure:
	@cd ${WRKSRC}; ${ACLOCAL} -I ${LOCALBASE}/share/aclocal -I ${X11BASE}/share/aclocal

.include <bsd.port.mk>
