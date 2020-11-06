# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Jabber-Lite
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BEECEE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standalone library for communicating with Jabber servers

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
		p5-Net-DNS>=0:dns/p5-Net-DNS

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
