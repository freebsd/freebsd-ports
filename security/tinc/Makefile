# ex:ts=8
# Ports collection makefile for:	tinc
# Date created:			Jul 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tinc
PORTVERSION=	1.0p8
CATEGORIES=	security
MASTER_SITES=	http://tinc.nl.linux.org/packages/ \
		ftp://ftp.wiretapped.net/pub/security/network-security/tinc/ \
		http://the.wiretapped.net/security/network-security/tinc/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv \
		intl:${PORTSDIR}/devel/gettext

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN5=	tinc.conf.5
MAN8=	tincd.8

.include <bsd.port.mk>
