# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Whois-IP
PORTVERSION=	1.12
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl extension for looking up the whois information for IP addresses

BUILD_DEPENDS=	p5-Regexp-IPv6>=0.02:${PORTSDIR}/textproc/p5-Regexp-IPv6
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=		Net::Whois::IP.3

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
.include <bsd.port.mk>
