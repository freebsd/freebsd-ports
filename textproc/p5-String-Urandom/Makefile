# $FreeBSD$

PORTNAME=	String-Urandom
PORTVERSION=	0.16
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to convert /dev/urandom to 8-bit chars

RUN_DEPENDS=	\
	p5-Params-Validate>0:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	String::Urandom.3

.include <bsd.port.mk>
