# New ports collection makefile for:        iplog
# Version required:	2.0-1017
# Date created:		4 Oct 1999
# Whom:			Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

DISTNAME=	iplog-2.0-1017
CATEGORIES=	security
MASTER_SITES=	http://www.numb.org/~odin/stuff/

MAINTAINER=	dr@domix.de

GNU_CONFIGURE=	yes
MAKE_FLAGS=	CONF_ARGS="--prefix=${PREFIX}"
USE_GMAKE=	yes

MAN8=	iplog.8

post-install:
	strip ${PREFIX}/sbin/iplog
	${CP} ${WRKSRC}/example-iplog.rules ${PREFIX}/etc/iplog.rules.sample
	${CP} ${WRKSRC}/example-iplog.rules ${PREFIX}/etc/iplog.rules

.include <bsd.port.mk>
