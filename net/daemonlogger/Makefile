PORTNAME=	daemonlogger
PORTVERSION=	1.2.2
DISTVERSIONPREFIX=	V
CATEGORIES=	net

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Packet sniffer capable of running as a daemon and as a software tap

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdnet.so:net/libdnet

GNU_CONFIGURE=	yes
USE_RC_SUBR=	daemonlogger

USE_GITHUB=	yes
GH_ACCOUNT=	Cisco-Talos
GH_PROJECT=	Daemonlogger

PLIST_FILES=	bin/daemonlogger

.include <bsd.port.mk>
