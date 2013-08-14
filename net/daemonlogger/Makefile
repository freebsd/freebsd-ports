# $FreeBSD$

PORTNAME=	daemonlogger
PORTVERSION=	1.2.1
CATEGORIES=	net
MASTER_SITES=	http://www.snort.org/users/roesch/code/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	A packet sniffer capable of running as a daemon and as a software tap

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet

GNU_CONFIGURE=	yes
USE_RC_SUBR=	daemonlogger

PLIST_FILES=	bin/daemonlogger

.include <bsd.port.mk>
