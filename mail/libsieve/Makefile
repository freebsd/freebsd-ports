# New ports collection makefile for:	libsieve
# Date created:				4 August 2006
# Whom:					Mark Starovoytov <mark_sf@kikg.ifmo.ru>
#
# $FreeBSD$
#

PORTNAME=	libsieve
PORTVERSION=	2.2.6
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	mark_sf@kikg.ifmo.ru
COMMENT=	A library for parsing, sorting and filtering mail

GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=${WRKSRC}/src
CONFIGURE_ARGS+=--prefix=${PREFIX}
USE_GMAKE=	yes
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src
USE_BISON=	build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
