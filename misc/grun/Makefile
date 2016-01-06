# Created by: domi@saargate.de
# $FreeBSD$

PORTNAME=	grun
PORTVERSION=	0.8.1
PORTREVISION=	7
CATEGORIES=	misc
MASTER_SITES=	http://www.brettnacher.org/users/dominik/FreeBSD/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk-launcher similar to the Windows(tm) "Run..." dialog

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-testfile

PLIST_FILES=	bin/grun %%DATADIR%%/consfile %%DATADIR%%/gassoc \
		man/man1/grun.1x.gz

.include <bsd.port.mk>
