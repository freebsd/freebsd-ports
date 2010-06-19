# New ports collection makefile for:	chpasswd
# Date created:		18 December 2003
# Whom:			Jean Milanez Melo <jmelo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	chpasswd
PORTVERSION=	2.2.3
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	SF/orso${PORTNAME}/orso${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allow users to change their Squid or Web password using the browser

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}/etc/chpasswd \
		--enable-language=English \
		--enable-cgidir=${PREFIX}/www/cgi-bin

pre-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin

post-install:
	@${ECHO} 'Remember, passwd and log file must be owned by httpd user, or chmod 777'

.include <bsd.port.mk>
