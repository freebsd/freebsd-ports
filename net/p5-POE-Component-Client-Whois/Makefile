# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	POE-Component-Client-Whois
PORTVERSION=	1.28
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	One shot non-blocking RFC 812 WHOIS query

RUN_DEPENDS=	p5-POE>=0.38:${PORTSDIR}/devel/p5-POE \
		p5-Net-Netmask>=1.9012:${PORTSDIR}/net-mgmt/p5-Net-Netmask

USES=		perl5
USE_PERL5=	configure

MAN3=		POE::Component::Client::Whois.3 \
		POE::Component::Client::Whois::IPBlks.3 \
		POE::Component::Client::Whois::TLDList.3

.include <bsd.port.mk>
