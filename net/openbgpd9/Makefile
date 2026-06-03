PORTNAME=	openbgpd
PORTVERSION=	9.0
CATEGORIES=	net
MASTER_SITES=	OPENBSD/OpenBGPD
PKGNAMESUFFIX=	9

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4
WWW=		https://www.openbgpd.org/

LICENSE=	MIT
LICENSE_FILE=	${FILESDIR}/COPYING

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		autoreconf libtool localbase pathfix uidfix
USE_RC_SUBR=	${PORTNAME} openbgplgd

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	"--with-wwwrunstatedir=/var/run"

CONFLICTS=	quagga zebra

SUB_FILES=	pkg-message

USERS=		_bgpd
GROUPS=		_bgpd

OPTIONS_DEFINE=		BGPLGD
OPTIONS_DEFAULT=	BGPLGD
OPTIONS_SUB=		BGPLGD

BGPLGD_DESC=		Build with Looking Glass Daemon
BGPLGD_CONFIGURE_WITH=	bgplgd

BGPLGD_GROUPS=	_bgplgd
BGPLGD_USERS=	_bgplgd

.include <bsd.port.mk>
