# New ports collection makefile for:	etherape
# Date created:				4 April 2001
# Whom: 				Holger Lamm <holger@eit.uni-kl.de>
#
# $FreeBSD$
#

PORTNAME=	etherape
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	samy@kerneled.com
COMMENT=	A graphical network traffic visualization tool for gnome

USE_GETTEXT=	yes
USE_GNOME=	libglade2 libgnomeui
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		etherape.1

.include <bsd.port.mk>
