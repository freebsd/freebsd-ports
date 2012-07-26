# Ports collection makefile for:	libmrss
# Date created:			Jan 2, 2007
# Whom:				Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmrss
PORTVERSION=	0.19.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.autistici.org/bakunin/libmrss/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A C library for parsing, writing, and creating RSS

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		nxml.18:${PORTSDIR}/textproc/libnxml

OPTIONS=	PHPMRSS "support to PHP" on

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
WANT_GNOME=	yes

pre-patch:
		${gnomehack_PRE_PATCH}

.include <bsd.port.pre.mk>

.if defined(WITH_PHPMRSS)
BROKEN=		does not compile
USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_AUTOTOOLS+=	autoconf:env
post-install:
		@(cd ${WRKSRC}/phpmrss; ${SETENV} ${SCRIPTS_ENV} ${LOCALBASE}/bin/phpize)
		@(cd ${WRKSRC}/phpmrss; ${SETENV} ${SCRIPTS_ENV} CC=${CC} ./configure; ${MAKE} install)
PLIST_SUB+=	PHPMRSS=""
.else
PLIST_SUB+=	PHPMRSS="@comment "
.endif

.include <bsd.port.post.mk>
