# New ports collection makefile for:	chpasswd
# Date created:		18 December 2003
# Whom:			Jean Milanez Melo <jmelo@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	chpasswd
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://web.onda.com.br/orso/

MAINTAINER=	jmelo@freebsdbrasil.com.br
COMMENT=	Allow users to change their Squid or Web password using the browser

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}/etc/chpasswd \
		--enable-language=English \
		--enable-cgidir=${PREFIX}/www/cgi-bin \

.include <bsd.port.mk>
