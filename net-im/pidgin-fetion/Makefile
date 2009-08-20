# New ports collection makefile for:	pidgin-fetion
# Date created:				17 October 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	fetion
PORTVERSION=	0.98.5
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://www.logvinov.ru/files/dist/fetion/
PKGNAMEPREFIX=	pidgin-

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Fetion protocol plugin for libpurple

LIB_DEPENDS=	purple.6:${PORTSDIR}/net-im/libpurple

MAKE_JOBS_SAFE=	yes

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
