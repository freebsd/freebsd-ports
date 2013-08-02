# Created by: chinsan
# $FreeBSD$

PORTNAME=	POE-Component-Client-MSN
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE Component for MSN Messenger

DEPRECATED=	Primary MSN Messenger service terminated 30 APR 2013
EXPIRATION_DATE=2013-10-31

BUILD_DEPENDS=	p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		p5-POE-Component-Client-HTTP>=0:${PORTSDIR}/www/p5-POE-Component-Client-HTTP \
		p5-POE-Component-Client-Keepalive>=0:${PORTSDIR}/net/p5-POE-Component-Client-Keepalive \
		p5-POE-Component-SSLify>=0:${PORTSDIR}/security/p5-POE-Component-SSLify \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=		POE::Component::Client::MSN.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
