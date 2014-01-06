# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Twitter-Lite
PORTVERSION=	0.12001
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	max@FreeBSD.org
COMMENT=	Perl interface to the Twitter API

BUILD_DEPENDS=	p5-JSON>=2.02:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Memoize>=0:${PORTSDIR}/devel/p5-Memoize \
		p5-URI>=1.4:${PORTSDIR}/net/p5-URI \
		p5-Net-OAuth>=0.25:${PORTSDIR}/net/p5-Net-OAuth \
		p5-Crypt-SSLeay>=0.5:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	p5-JSON>=2.02:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Memoize>=0:${PORTSDIR}/devel/p5-Memoize \
		p5-URI>=1.4:${PORTSDIR}/net/p5-URI \
		p5-Net-OAuth>=0.25:${PORTSDIR}/net/p5-Net-OAuth \
		p5-Crypt-SSLeay>=0.5:${PORTSDIR}/security/p5-Crypt-SSLeay

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
