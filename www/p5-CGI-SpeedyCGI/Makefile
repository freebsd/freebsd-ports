# New ports collection makefile for:	CGI-SpeedyCGI
# Date created:				Sun Mar 10 16:44:06 CET 2002
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	CGI-SpeedyCGI
PORTVERSION=	2.21
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	Speed up perl CGI scripts by running them persistently

PERL_CONFIGURE=	yes

post-configure:
	@${PERL} -pi.bak -e 's,^PREFIX = /usr$$,PREFIX = ${PREFIX},g' ${WRKSRC}/*/Makefile

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/speedy/speedy ${PREFIX}/bin/speedy_suid
	@${CHMOD} 4755 ${PREFIX}/bin/speedy_suid

.include <bsd.port.mk>
