# New ports collection makefile for:	admuser
# Date created:		18 December 2003
# Whom:			Jean Milanez Melo <jmelo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	admuser
PORTVERSION=	2.3.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://sarg.sourceforge.net/

MAINTAINER=	jmelo@FreeBSD.org
COMMENT=	Handle your Squid or Web users and passwords using your browser

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}/etc/admuser \
		--enable-language=English \
		--enable-cgidir=${PREFIX}/www/cgi-bin \

.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 700000)
BROKEN=		Does not compile on 7.X
.endif

pre-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin

.include <bsd.port.post.mk>
