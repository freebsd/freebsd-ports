# New ports collection makefile for:   nc6
# Date created:                30 May 2002
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	nc6
PORTVERSION=	0.5
PORTREVISION=	2	
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.deepspace6.net/pub/ds6/sources/nc6/ \
		http://ftp.deepspace6.net/pub/ds6/sources/nc6/

MAINTAINER=	filippo@widestore.net
COMMENT=	Netcat clone with IPv6 support

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		intl.5:${PORTSDIR}/devel/gettext-old

MAN1=	nc6.1
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
