# New ports collection makefile for:	libmms
# Date created:				25 Dec 2004
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmms
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for parsing mms:// and mmsh:// type network streams

USE_REINPLACE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig glib20
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes

pre-configure:
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib.h|' \
		${WRKSRC}/src/uri.c

.include <bsd.port.mk>
