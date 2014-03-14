# Created by: Daniel B. Hemmerich <dan@spot.org>
# $FreeBSD$

PORTNAME=	Text-FIGlet
PORTVERSION=	2.19.3
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module to provide FIGlet abilities, akin to banner

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	${LOCALBASE}/bin/figlet:${PORTSDIR}/misc/figlet
TEST_DEPENDS=	p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

USE_PERL5=	configure
USES=		perl5 tar:tgz

.include <bsd.port.mk>
