# Created by: <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	Net-Async-XMPP
PORTVERSION=	0.002
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEAM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Asynchronous XMPP client and server

RUN_DEPENDS=	p5-IO-Async>=0.37:${PORTSDIR}/devel/p5-IO-Async \
		p5-IO-Async-SSL>=0.04:${PORTSDIR}/security/p5-IO-Async-SSL \
		p5-Protocol-XMPP>=0.002:${PORTSDIR}/net-im/p5-Protocol-XMPP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
