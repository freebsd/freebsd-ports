PORTNAME=	openbgpd
PORTVERSION=	7.7
CATEGORIES=	net
MASTER_SITES=	OPENBSD/OpenBGPD
PKGNAMESUFFIX=	7

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4
WWW=		https://www.openbgpd.org/

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/COPYING

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		autoreconf libtool localbase pathfix uidfix
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

USERS=		_bgpd
GROUPS=		_bgpd

CONFLICTS=	zebra quagga

.include <bsd.port.mk>
