# New ports collection makefile for:	admuser
# Date created:		18 December 2003
# Whom:			Jean Milanez Melo <jmelo@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	admuser
PORTVERSION=	2.3
CATEGORIES=	www
MASTER_SITES=	http://web.onda.com.br/orso/

MAINTAINER=	jmelo@freebsdbrasil.com.br
COMMENT=	Handle your Squid or Web users and passwords using your browser

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}/etc/admuser \
		--enable-language=English \
		--enable-cgidir=${PREFIX}/www/cgi-bin \

.include <bsd.port.mk>
