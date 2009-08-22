# New ports collection makefile for:	peacock
# Date created:				21st April 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	peacock
PORTVERSION=	1.9.1
PORTREVISION=	14
CATEGORIES=	www gnome
MASTER_SITES=	SF

MAINTAINER=	pav@FreeBSD.org
COMMENT=	A GUI-based HTML Editor for GTK+/GNOME

LIB_DEPENDS=	gtkhtml-3.8.15:${PORTSDIR}/www/gtkhtml38

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui gtksourceview
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
