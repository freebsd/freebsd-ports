PORTNAME=	openbgpd
PORTVERSION=	8.8
CATEGORIES=	net
MASTER_SITES=	OPENBSD/OpenBGPD
PKGNAMESUFFIX=	8

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4
WWW=		https://www.openbgpd.org/

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/COPYING

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		autoreconf libtool localbase pathfix uidfix
USE_RC_SUBR=	${PORTNAME} openbgplgd

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS="--with-wwwrunstatedir=/var/run"

OPTIONS_DEFINE= BGPLGD
OPTIONS_SUB= BGPLGD
OPTIONS_DEFAULT= BGPLGD

BGPLGD_DESC= Build with Looking Glass Daemon
BGPLGD_CONFIGURE_WITH= bgplgd

SUB_FILES=	pkg-message

USERS=		_bgpd
GROUPS=		_bgpd

BGPLGD_USERS+= _bgplgd
BGPLGD_GROUPS+= _bgplgd


CONFLICTS=	zebra quagga

.include <bsd.port.mk>
