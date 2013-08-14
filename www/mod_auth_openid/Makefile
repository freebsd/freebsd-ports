# Created by: Sutra Zhou <zhoushuqun@gmail.com>
# $FreeBSD$

PORTNAME=	mod_auth_openid
PORTVERSION=	0.7
CATEGORIES=	www
MASTER_SITES=	http://cloud.github.com/downloads/bmuller/mod_auth_openid/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	An authentication module for the Apache 2 webserver with OpenID

LIB_DEPENDS=	opkele:${PORTSDIR}/devel/libopkele \
		sqlite3:${PORTSDIR}/databases/sqlite3


PLIST_FILES=	${APACHEMODDIR}/mod_auth_openid.so

USE_APACHE=	22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre=${LOCALBASE}

CFLAGS+=	-I${LOCALBASE}/include -I/usr/include/openssl

.include <bsd.port.mk>
