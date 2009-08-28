# New ports collection makefile for:	libmms
# Date created:				25 Dec 2004
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmms
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for parsing mms:// and mmsh:// type network streams

USE_GNOME=	gnomehack gnometarget pkgconfig glib20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib.h|' \
		${WRKSRC}/src/uri.c

.include <bsd.port.mk>
