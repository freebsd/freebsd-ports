# New ports collection makefile for:	p5-HTTP-Daemon-SSL
# Date created:				August 27, 2008
# Whom:					Mykola Marzhan <delgod@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Daemon-SSL
PORTVERSION=	1.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	delgod@portaone.com
COMMENT=	A simple http server class with SSL support

RUN_DEPENDS=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/HTTP/Daemon.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		HTTP::Daemon::SSL.3

.include <bsd.port.mk>
