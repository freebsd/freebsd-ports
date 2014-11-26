# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	WebService-Pushover
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Interface to Pushover API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Moo>=0:${PORTSDIR}/devel/p5-Moo \
		p5-Net-HTTP-Spore>=0:${PORTSDIR}/net/p5-Net-HTTP-Spore \
		p5-Net-HTTP-Spore-Middleware-Header>=0:${PORTSDIR}/net/p5-Net-HTTP-Spore-Middleware-Header \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Test-Perl-Critic \
		p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
