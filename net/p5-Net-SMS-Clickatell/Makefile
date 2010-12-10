# New ports collection makefile for:	p5-Net-SMS-Clickatell
# Date created:		2010-12-01
# Whom:			John Bayly <freebsd.ports@tipstrade.net>
#
# $FreeBSD$
#

PORTNAME=	Net-SMS-Clickatell
PORTVERSION=	0.05
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd.ports@tipstrade.net
COMMENT=	Access to Clickatell SMS messaging service

PERL_CONFIGURE=	yes

MAN3=		Net::SMS::Clickatell.3

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
