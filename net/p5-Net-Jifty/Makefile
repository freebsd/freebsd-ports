# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Jifty
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to online Jifty applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Any-Moose>=0.04:devel/p5-Any-Moose \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-Email-Address>=0:mail/p5-Email-Address \
		p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-URI>=0:net/p5-URI \
		p5-YAML>=0:textproc/p5-YAML \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
