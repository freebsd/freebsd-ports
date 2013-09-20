# Created by: Brian Handy <handy@physics.montana.edu>
# $FreeBSD$

PORTNAME=	astime
PORTVERSION=	2.8
PORTREVISION=	2
CATEGORIES=	x11-clocks afterstep
MASTER_SITES=	ftp://ftp.afterstep.org/apps/astime/ \
		http://www.tigr.net/afterstep/download/astime/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time/Date applet for WindowMaker

USE_XORG=	xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xpm-library="${LOCALBASE}/lib" --with-xpm-includes="${LOCALBASE}/include/X11"
INSTALL_TARGET=	install install.man

MAN1=		astime.1
PLIST_FILES=	bin/astime

NO_STAGE=	yes
.include <bsd.port.mk>
