# New ports collection makefile for:	grun
# Date created:			Sun Jul 18 1999
# Whom:				domi@saargate.de
#
# $FreeBSD$
#

PORTNAME=	grun
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.brettnacher.org/users/dominik/FreeBSD/

MAINTAINER=	domi@saargate.de
COMMENT=	Gtk-launcher similar to the Windows(tm) "Run..." dialog

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-testfile

MAN1=		grun.1x

PLIST_FILES=	bin/grun %%DATADIR%%/consfile %%DATADIR%%/gassoc
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
