# New ports collection makefile for:	fribidi
# Date created:				17 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fribidi
PORTVERSION=	0.1.12
CATEGORIES=	textproc devel
MASTER_SITES=	http://imagic.weizmann.ac.il/~dov/freesw/FriBidi/

PATCH_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.3/dependencies/
PATCHFILES=	fribidi-0.1.12-glib2.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	glib-1.3.2:${PORTSDIR}/devel/glib13

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
