# Ports collection makefile for:    macipgw
# Version required:     macipgw-1.0
# Date created:         25 Nov 1997
# Whom:                 stb
#
# $Id: Makefile,v 1.1.1.1 1997/12/04 20:12:56 stb Exp $
#

DISTNAME=       macipgw-1.0
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.promo.de/pub/people/stefan/netatalk/

MAINTAINER=	stb@freebsd.org

BUILD_DEPENDS=	${PREFIX}/lib/libatalk.a:${PORTSDIR}/net/netatalk \
		${PREFIX}/include/atalk/ddp.h:${PORTSDIR}/net/netatalk
RUN_DEPENDS=	${PREFIX}/libexec/atalkd:${PORTSDIR}/net/netatalk

.include <bsd.port.mk>
