# New ports collection makefile for:	admuser
# Date created:		18 December 2003
# Whom:			Jean Milanez Melo <jmelo@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	admuser
PORTVERSION=	2.3.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://sarg.sourceforge.net/

MAINTAINER=	jmelo@freebsdbrasil.com.br
COMMENT=	Handle your Squid or Web users and passwords using your browser

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}/etc/admuser \
		--enable-language=English \
		--enable-cgidir=${PREFIX}/www/cgi-bin \

pre-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin

#BROKEN=		"Install fails"

.include <bsd.port.mk>
