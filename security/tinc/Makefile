# ex:ts=8
# Ports collection makefile for:	tinc
# Date created:			Jul 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tinc
PORTVERSION=	1.0.19
CATEGORIES=	security
MASTER_SITES=	http://www.tinc-vpn.org/packages/ \
		ftp://ftp.wiretapped.net/pub/security/network-security/tinc/ \
		http://www.mirrors.wiretapped.net/security/network-security/tinc/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A Virtual Private Network (VPN) daemon

LIB_DEPENDS=	lzo2.2:${PORTSDIR}/archivers/lzo2

LICENSE=	GPLv3

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--localstatedir=/var
USE_RC_SUBR=	tincd.sh

PLIST_FILES=	sbin/tincd
MAN5=	tinc.conf.5
MAN8=	tincd.8
INFO=	tinc

.include <bsd.port.mk>
