# New ports collection makefile for:   gtkhx
# Date created:        9 February 2002
# Whom:                Josh Elsasser <jre@vineyard.net>
#
# $FreeBSD$
#

PORTNAME=	gtkhx
PORTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkhx

MAINTAINER=	jre@vineyard.net
COMMENT=	A GTK+ version of Hx, a UNIX Hotline Client

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_XLIB=	yes
USE_GNOME=	gdkpixbuf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${PREFIX}

MAN1=		gtkhx.1

.include <bsd.port.mk>
