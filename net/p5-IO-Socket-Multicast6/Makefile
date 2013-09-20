# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	IO-Socket-Multicast6
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Send and receive IPv4 and IPv6 multicast messages

BUILD_DEPENDS=	p5-IO-Interface>=1.01:${PORTSDIR}/net/p5-IO-Interface \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		p5-Socket-Multicast6>=0.01:${PORTSDIR}/net/p5-Socket-Multicast6 \
		p5-Socket6>=0.19:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		IO::Socket::Multicast6.3

NO_STAGE=	yes
.include <bsd.port.mk>
