# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Net-RTP
PORTVERSION=	0.09
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Send and receive RTP packets (RFC3550)

RUN_DEPENDS=	p5-IO-Socket-Multicast6>=0.02:${PORTSDIR}/net/p5-IO-Socket-Multicast6 \
		p5-IO-Socket-Multicast>=1.00:${PORTSDIR}/net/p5-IO-Socket-Multicast \
		p5-IO-Socket-INET6>=1.20:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		p5-Socket6>=0.19:${PORTSDIR}/net/p5-Socket6

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
