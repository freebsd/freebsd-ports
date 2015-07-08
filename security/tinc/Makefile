# Created by: ijliao
# $FreeBSD$

PORTNAME=	tinc
PORTVERSION=	1.0.26
CATEGORIES=	security
MASTER_SITES=	http://www.tinc-vpn.org/packages/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Virtual Private Network (VPN) daemon

LIB_DEPENDS=	liblzo2.so:${PORTSDIR}/archivers/lzo2

LICENSE=	GPLv3

USES=		cpe makeinfo
CPE_VENDOR=	tinc-vpn
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
