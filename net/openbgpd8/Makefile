PORTNAME=	openbgpd
PORTVERSION=	8.4
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
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

SUB_FILES=	pkg-message

USERS=		_bgpd
GROUPS=		_bgpd

CONFLICTS=	zebra quagga

.include <bsd.port.mk>
