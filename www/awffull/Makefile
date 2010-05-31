# New ports collection makefile for: awffull
# Date created:		5 Feburary 2008
# Whom:			Chadwick Sorrell chad@wickdev.com
#
# $FreeBSD$
#

PORTNAME=	awffull
PORTVERSION=	3.10.2
PORTREVISION=	5
CATEGORIES?=	www
MASTER_SITES=	http://www.stedee.id.au/files/

MAINTAINER?=	chad@wickdev.com
COMMENT=	AWFFull is a webserver log analysis tool forked from Webalizer

BUILD_DEPENDS=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		png.6:${PORTSDIR}/graphics/png \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS?=	ja-awffull-[0-9]*

FONTDEFAULT?=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/VeraBd.ttf
FONTLABEL?=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf

OPTIONS=	GEOIP "Enable support for GeoIP (Country Detection)" Off

USE_ICONV=	yes
USE_GETTEXT=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-font-default=${FONTDEFAULT} \
		--with-font-label=${FONTLABEL} \
		--with-etcdir=${PREFIX}/etc
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

MAN1=		awffull.1
MAN5=		awffull.conf.5

.include <bsd.port.pre.mk>

.if defined(WITH_GEOIP)
LIB_DEPENDS+=	GeoIP.5:${PORTSDIR}/net/GeoIP
CONFIGURE_ARGS+=--enable-geoip
.else
CONFIGURE_ARGS+=--disable-geoip
.endif

.include <bsd.port.post.mk>
