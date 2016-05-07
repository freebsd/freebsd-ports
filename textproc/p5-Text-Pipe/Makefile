# $FreeBSD$

PORTNAME=	Text-Pipe
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for common text filter API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Class-Accessor-Complex>0:devel/p5-Class-Accessor-Complex \
	p5-Class-Accessor-Constructor>0:devel/p5-Class-Accessor-Constructor \
	p5-Sub-Name>0:devel/p5-Sub-Name \
	p5-UNIVERSAL-require>0:devel/p5-UNIVERSAL-require
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
# Hack to avoid invoking CPAN.pm downloading...
CONFIGURE_ENV=	PERL5_CPANPLUS_IS_RUNNING=1

.include <bsd.port.mk>
