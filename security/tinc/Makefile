# ex:ts=8
# Ports collection makefile for:	tinc
# Date created:			Jul 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tinc
PORTVERSION=	1.0p8
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://tinc.nl.linux.org/packages/ \
		ftp://ftp.wiretapped.net/pub/security/network-security/tinc/ \
		http://the.wiretapped.net/security/network-security/tinc/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A Virtual Private Network (VPN) daemon

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		MAKEINFO="makeinfo --no-split"

MAN5=	tinc.conf.5
MAN8=	tincd.8

post-extract:
	@${RM} -f ${WRKSRC}/doc/tinc.info*

.include <bsd.port.mk>
