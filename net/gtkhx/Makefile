# New ports collection makefile for:   gtkhx
# Date created:        9 February 2002
# Whom:                Josh Elsasser <jre@vineyard.net>
#
# $FreeBSD$
#

PORTNAME=	gtkhx
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkhx

MAINTAINER=	jre@vineyard.net

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_XLIB=	yes
USE_GNOMENG=	yes
USE_GNOME=	gdkpixbuf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${PREFIX}

MAN1=		gtkhx.1

.include <bsd.port.mk>
