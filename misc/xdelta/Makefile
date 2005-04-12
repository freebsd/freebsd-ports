# New ports collection makefile for:		xdelta
# Date created:					Sun May  4 21:40:06 CDT 1997
# Whom:						jmacd
#
# $FreeBSD$
#

PORTNAME=	xdelta
PORTVERSION=	1.1.3
CATEGORIES=	misc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	c9710216@atlas.newcastle.edu.au
COMMENT=	A diff/patch utility for binary files

USE_GNOME=	glib12
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		xdelta.1

.include <bsd.port.mk>
