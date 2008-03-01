# Ports collection makefile for:	libmrss
# Date created:			Jan 2, 2007
# Whom:				Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmrss
PORTVERSION=	0.19.1
PORTREVISION=	0
CATEGORIES=	textproc
MASTER_SITES=	http://www.autistici.org/bakunin/libmrss/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A C library for parsing, writing, and creating RSS

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl \
		nxml.18:${PORTSDIR}/textproc/libnxml

OPTIONS=	PHPMRSS "support to PHP" on

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

USE_LDCONFIG=	yes
WANT_GNOME=	yes

pre-patch:
		${gnomehack_PRE_PATCH}

.include <bsd.port.pre.mk>

.if defined(WITH_PHPMRSS)
USE_PHP=	yes
USE_AUTOTOOLS+=	autoconf:261:env
BUILD_DEPENDS+=	phpize:${PHP_PORT}
post-install:
		@(cd ${WRKSRC}/phpmrss; ${SETENV} ${SCRIPTS_ENV} ${LOCALBASE}/bin/phpize)
		@(cd ${WRKSRC}/phpmrss; ./configure; ${MAKE} install)
PLIST_SUB+=	PHPMRSS=""
.else
PLIST_SUB+=	PHPMRSS="@comment "
.endif

.include <bsd.port.post.mk>
