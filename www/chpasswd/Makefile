# New ports collection makefile for:	chpasswd
# Date created:		18 December 2003
# Whom:			Jean Milanez Melo <jmelo@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	chpasswd
PORTVERSION=	2.2.3
CATEGORIES=	www
MASTER_SITES=	http://ufpr.dl.sourceforge.net/sourceforge/orsochpasswd/ \
		http://optusnet.dl.sourceforge.net/sourceforge/orsochpasswd/ \
		http://keihanna.dl.sourceforge.net/sourceforge/orsochpasswd/

MAINTAINER=	jmelo@freebsdbrasil.com.br
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
