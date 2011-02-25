# New ports collection makefile for:	gnome-specimen
# Date created:		2010-08-08
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	gnome-specimen
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://uwstopia.nl/geek/projects/gnome-specimen/releases/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Gnome Specimen is a simple tool to preview and compare installed fonts

GNU_CONFIGURE=	yes
USE_GNOME=	pygnomedesktop
GCONF_SCHEMAS=	gnome-specimen.schemas
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	automake:env autoconf:env

INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

pre-configure:
	( cd ${WRKSRC} ; ${AUTORECONF} ; ${AUTOMAKE} )

.include <bsd.port.post.mk>
