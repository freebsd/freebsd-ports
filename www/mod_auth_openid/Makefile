# New ports collection makefile for:	mod_auth_openid
# Date created:				3 August 2008
# Whom:					Sutra Zhou <zhoushuqun@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_openid
PORTVERSION=	0.4
CATEGORIES=	www
MASTER_SITES=	http://butterfat.net/releases/mod_auth_openid/

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	An authentication module for the Apache 2 webserver with OpenID

BUILD_DEPENDS=	apr-1-config:${PORTSDIR}/devel/apr
LIB_DEPENDS=	opkele:${PORTSDIR}/devel/libopkele \
		sqlite3:${PORTSDIR}/databases/sqlite34

MAKE_JOBS_SAFE=  yes

PLIST_FILES=	${APACHEMODDIR}/mod_auth_openid.so

USE_APACHE=	2.0+
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre=${LOCALBASE}

CFLAGS+=	-I${LOCALBASE}/include -I/usr/include/openssl

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		Doesn't compile on 6.x
.endif

.include <bsd.port.post.mk>
