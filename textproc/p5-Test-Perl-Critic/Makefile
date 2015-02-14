# Created by: chinsan
# $FreeBSD$

PORTNAME=	Test-Perl-Critic
PORTVERSION=	1.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use Perl::Critic in test programs

BUILD_DEPENDS=	p5-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Perl-Critic \
		p5-MCE>=1.52:${PORTSDIR}/devel/p5-MCE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
