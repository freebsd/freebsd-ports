# New ports collection makefile for:        iplog
# Version required:	2.1.1
# Date created:		4 Oct 1999
# Whom:			Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

DISTNAME=	iplog-2.1.1
CATEGORIES=	security
MASTER_SITES=	http://download.sourceforge.net/ojnk/ \
		ftp://ftp.karlsbakk.net/pub/ojnk/iplog/

PATCH_SITES=	http://ojnk.sourceforge.net/stuff/ \
		ftp://ftp.karlsbakk.net/pub/ojnk/iplog/
PATCH_DIST_STRIP=-p1

MAINTAINER=	ust@cert.siemens.de

GNU_CONFIGURE=	yes
MAKE_FLAGS=	CONF_ARGS="--prefix=${PREFIX}"
USE_GMAKE=	yes

MAN5=	iplog.rules.5
MAN8=	iplog.8

.include <bsd.port.pre.mk>

post-install:
	strip ${PREFIX}/sbin/iplog
.if !exists(${PREFIX}/etc/iplog.rules)
	${CP} ${WRKSRC}/example-iplog.rules ${PREFIX}/etc/iplog.rules
.endif
	${CP} ${WRKSRC}/example-iplog.rules ${PREFIX}/etc/iplog.rules.sample

.include <bsd.port.post.mk>
