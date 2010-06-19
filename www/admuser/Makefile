# New ports collection makefile for:	admuser
# Date created:		18 December 2003
# Whom:			Jean Milanez Melo <jmelo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	admuser
PORTVERSION=	2.3.2
CATEGORIES=	www
MASTER_SITES=	http://sarg.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Handle your Squid or Web users and passwords using your browser

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}/etc/admuser \
		--enable-language=English \
		--enable-cgidir=${PREFIX}/www/cgi-bin \

.include <bsd.port.pre.mk>

pre-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin

.include <bsd.port.post.mk>
