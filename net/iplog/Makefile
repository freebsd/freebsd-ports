# New ports collection makefile for:        iplog
# Date created:		4 Oct 1999
# Whom:			Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	iplog
PORTVERSION=	2.2.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.karlsbakk.net/pub/ojnk/iplog/
MASTER_SITE_SUBDIR=	ojnk

PATCH_SITES=	http://ojnk.sourceforge.net/stuff/ \
		ftp://ftp.karlsbakk.net/pub/ojnk/iplog/
PATCH_DIST_STRIP=-p1

MAINTAINER=	ust@cert.siemens.de

GNU_CONFIGURE=	yes
MAKE_FLAGS=	CONF_ARGS="--prefix=${PREFIX}"
USE_GMAKE=	yes

MAN5=	iplog.conf.5
MAN8=	iplog.8

.include <bsd.port.pre.mk>

post-install:
	@strip ${PREFIX}/sbin/iplog
.if !exists(${PREFIX}/etc/iplog.conf)
	@${CP} ${WRKSRC}/example-iplog.conf ${PREFIX}/etc/iplog.conf
.else
	@echo
	@echo "============================================================================"
	@echo "Hint:	iplog changed its configuration file from ${PREFIX}/etc/iplog.rules"
	@echo "	to ${PREFIX}/etc/iplog.conf"
	@echo
	@echo "See ${PREFIX}/etc/example-iplog.conf for an example"
	@echo "============================================================================"
	@echo
.endif
	@${CP} ${WRKSRC}/example-iplog.conf ${PREFIX}/etc/example-iplog.conf

.include <bsd.port.post.mk>
