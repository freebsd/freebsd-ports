# New ports collection makefile for:	peacock
# Date created:				21st April 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	peacock
PORTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	A GUI-based HTML Editor for GTK+/GNOME

LIB_DEPENDS=	gtkhtml-3.0.3:${PORTSDIR}/www/gtkhtml3

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui gtksourceview
USE_LIBTOOL=	yes

.include <bsd.port.mk>
