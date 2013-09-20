# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Jabber-Lite
PORTVERSION=	0.8
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Jabber
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Standalone library for communicating with Jabber servers

RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL

USES=		perl5
USE_PERL5=	configure

MAN3=		Jabber::Lite.3

NO_STAGE=	yes
.include <bsd.port.mk>
