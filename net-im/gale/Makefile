# New ports collection makefile for:    gale
# Date created:         14 July 2000
# Whom:                 Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	gale
PORTVERSION=	0.99e
CATEGORIES=	net
MASTER_SITES=	http://download.ofb.net/gale/
DISTNAME=	${PORTNAME}-${PORTVERSION}gg

MAINTAINER=	peterh@sapros.com

BUILD_DEPENDS=	${LOCALBASE}/lib/libgc.a:${PORTSDIR}/devel/boehm-gc
LIB_DEPENDS=	wwwcore.1:${PORTSDIR}/www/libwww \
		adns.1:${PORTSDIR}/net/adns

USE_OPENSSL=	yes
USE_AUTOCONF_VER=213
INSTALLS_SHLIB=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-I${LOCALBASE}/include/w3c-libwww
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
