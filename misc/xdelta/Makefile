# New ports collection makefile for:		xdelta
# Date created:					Sun May  4 21:40:06 CDT 1997
# Whom:						jmacd
#
# $FreeBSD$
#

PORTNAME=	xdelta
PORTVERSION=	1.1.4
CATEGORIES=	misc devel
MASTER_SITES=	http://xdelta.googlecode.com/files/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A diff/patch utility for binary files

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	glib12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		xdelta.1

.include <bsd.port.mk>
