# Created by: ijliao
# $FreeBSD$

PORTNAME=	tinc
PORTVERSION=	1.0.23
CATEGORIES=	security
MASTER_SITES=	http://www.tinc-vpn.org/packages/ \
		ftp://ftp.wiretapped.net/pub/security/network-security/tinc/ \
		http://www.mirrors.wiretapped.net/security/network-security/tinc/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A Virtual Private Network (VPN) daemon

LIB_DEPENDS=	liblzo2.so:${PORTSDIR}/archivers/lzo2

LICENSE=	GPLv3

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--localstatedir=/var
USE_RC_SUBR=	tincd
INFO=		tinc
PLIST_FILES=	sbin/tincd \
		man/man5/tinc.conf.5.gz man/man8/tincd.8.gz

.include <bsd.port.mk>
