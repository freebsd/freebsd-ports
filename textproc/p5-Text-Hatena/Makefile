# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Text-Hatena
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for formatting text with Hatena Style

BUILD_DEPENDS=	p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Parse-RecDescent>=1.94:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Regexp-Assemble>=0.28:${PORTSDIR}/devel/p5-Regexp-Assemble
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Base>=0:${PORTSDIR}/devel/p5-Test-Base

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
