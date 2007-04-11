# New ports collection makefile for:   daemonlogger
# Date created:        10 April 2007
# Whom:                Wesley Shields <wxs@atarininja.org>
#
# $FreeBSD$
#

PORTNAME=	daemonlogger
PORTVERSION=	0.9
CATEGORIES=	net
MASTER_SITES=	http://www.snort.org/dl/daemonlogger/

MAINTAINER=	wxs@atarininja.org
COMMENT=	A packet sniffer capable of running as a daemon and as a software tap

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet

GNU_CONFIGURE=	yes
USE_RC_SUBR=	daemonlogger.sh

PLIST_FILES=	bin/daemonlogger

.include <bsd.port.mk>
