# Created by: ijliao
# $FreeBSD$

PORTNAME=	tinc
PORTVERSION=	1.0.36
PORTREVISION=	1
CATEGORIES=	security net-vpn
MASTER_SITES=	https://www.tinc-vpn.org/packages/ \
		http://www.tinc-vpn.org/packages/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Virtual Private Network (VPN) daemon

LICENSE=	GPLv3

LIB_DEPENDS=	liblzo2.so:archivers/lzo2

USES=		cpe ssl makeinfo
CPE_VENDOR=	tinc-vpn
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--localstatedir=/var
USE_RC_SUBR=	tincd
INFO=		tinc
PLIST_FILES=	sbin/tincd \
		man/man5/tinc.conf.5.gz man/man8/tincd.8.gz

.include <bsd.port.mk>
