# Ports collection makefile for:    macipgw
# Version required:     macipgw-1.0
# Date created:         25 Nov 1997
# Whom:                 stb
#
# $FreeBSD$
#

DISTNAME=       macipgw-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.hanse.de/sites/transit/netatalk/ \
		http://www.freebsd.org/~stb/netatalk/

MAINTAINER=	stb@freebsd.org

BUILD_DEPENDS=	${PREFIX}/lib/libatalk.a:${PORTSDIR}/net/netatalk \
		${PREFIX}/include/atalk/ddp.h:${PORTSDIR}/net/netatalk
RUN_DEPENDS=	${PREFIX}/libexec/atalkd:${PORTSDIR}/net/netatalk

.include <bsd.port.mk>
