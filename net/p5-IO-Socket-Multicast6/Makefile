# New ports collection makefile for:	p5-IO-Socket-Multicast6
# Date created:		2007-03-10
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	IO-Socket-Multicast6
PORTVERSION=	0.03
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Send and receive IPv4 and IPv6 multicast messages

RUN_DEPENDS=	p5-Socket6>=0.19:${PORTSDIR}/net/p5-Socket6 \
		p5-IO-Interface>=1.01:${PORTSDIR}/net/p5-IO-Interface \
		p5-Socket-Multicast6>=0.01:${PORTSDIR}/net/p5-Socket-Multicast6 \
		${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-INET6

PERL_MODBUILD=	yes

MAN3=		IO::Socket::Multicast6.3

.include <bsd.port.mk>
