# New ports collection makefile for:	wmfsm
# Date created:				2 January 2001
# Whom:					Steven Enderle <panic@subphase.de>
#
# $FreeBSD$
#

PORTNAME=	wmfsm
PORTVERSION=	0.34
PORTREVISION=	2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.cs.ubc.ca/~cmg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays filesystem usage of mountpoints in a nice WindowMaker dockapp

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_XORG=	x11 xpm
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		wmfsm.1
PLIST_FILES=	bin/wmfsm

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
