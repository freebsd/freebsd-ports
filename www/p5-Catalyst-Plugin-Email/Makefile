# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Email
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Send emails with Catalyst

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Email-Send>=0:${PORTSDIR}/mail/p5-Email-Send \
		p5-Email-MIME>=0:${PORTSDIR}/mail/p5-Email-MIME
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Catalyst::Plugin::Email.3

.include <bsd.port.mk>
