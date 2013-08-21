# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JavaScript-Packer
PORTVERSION=	1.006.003
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl version of Dean Edwards' Packer.js

BUILD_DEPENDS=	p5-Regexp-RegGrp>=1.001.001:${PORTSDIR}/devel/p5-Regexp-RegGrp
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.22:${PORTSDIR}/devel/p5-Test-Pod

USE_PERL5=	configure
USES=		perl5

MAN3=		JavaScript::Packer.3

.include <bsd.port.mk>
