# New ports collection makefile for: awffull
# Date created:		5 Feburary 2008
# Whom:			Chadwick Sorrell chad@wickdev.com
#
# $FreeBSD$
#

PORTNAME=	awffull
PORTVERSION=	3.8.2
CATEGORIES=	www
MASTER_SITES=	http://www.stedee.id.au/files/

MAINTAINER=	chad@wickdev.com
COMMENT=	AWFFull is a webserver log analysis tool forked from Webalizer

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		png.5:${PORTSDIR}/graphics/png \
		pcre.0:${PORTSDIR}/devel/pcre

OPTIONS=	GEOIP "Enable support for GeoIP (Country Detection)" Off

USE_GETTEXT=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pnglib=${LOCALBASE}/lib

MAN1=		awffull.1

.include <bsd.port.pre.mk>

.if defined(WITH_GEOIP)
LIB_DEPENDS+=	GeoIP.5:${PORTSDIR}/net/GeoIP
.endif

.include <bsd.port.post.mk>
