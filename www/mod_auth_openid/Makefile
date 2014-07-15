# Created by: Sutra Zhou <zhoushuqun@gmail.com>
# $FreeBSD$

PORTNAME=	mod_auth_openid
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://cloud.github.com/downloads/bmuller/mod_auth_openid/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An authentication module for the Apache 2 webserver with OpenID

LIB_DEPENDS=	libopkele.so:${PORTSDIR}/devel/libopkele \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3


PLIST_FILES=	${APACHEMODDIR}/mod_auth_openid.so

USE_APACHE=	22
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre=${LOCALBASE}

CFLAGS+=	-I${LOCALBASE}/include -I/usr/include/openssl

NO_STAGE=	yes
.include <bsd.port.mk>
