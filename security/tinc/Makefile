# ex:ts=8
# Ports collection makefile for:	tinc
# Date created:			Jul 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tinc
PORTVERSION=	1.0.2
CATEGORIES=	security
MASTER_SITES=	http://tinc.nl.linux.org/packages/ \
		ftp://ftp.wiretapped.net/pub/security/network-security/tinc/ \
		http://the.wiretapped.net/security/network-security/tinc/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	A Virtual Private Network (VPN) daemon

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext-old \
		lzo.1:${PORTSDIR}/archivers/lzo

USE_OPENSSL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN5=	tinc.conf.5
MAN8=	tincd.8
INFO=	tinc

pre-configure:
	${REINPLACE_CMD} \
	    's/OpenSSL_add_all_algorithms/OpenSSL_add_all_ciphers/' \
	    ${WRKSRC}/configure

.include <bsd.port.mk>
