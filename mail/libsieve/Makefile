# New ports collection makefile for:	libsieve
# Date created:				4 August 2006
# Whom:					Mark Starovoytov <mark_sf@kikg.ifmo.ru>
#
# $FreeBSD$
#

PORTNAME=	libsieve
PORTVERSION=	2.2.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libsieve

MAINTAINER=	mark_sf@kikg.ifmo.ru
COMMENT=	A library for parsing, sorting and filtering mail

GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=${WRKSRC}/src
CONFIGURE_TARGET=--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=--prefix=${PREFIX}
USE_GMAKE=	yes
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src
USE_BISON=	yes
USE_LDCONFIG=	yes
# get rid of the `size_t' problem in header.y
USE_GCC=	3.2+

.include <bsd.port.mk>
