# $FreeBSD$

PORTNAME=	Text-LTSV
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Labeled Tab Separated Value manipulator

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Project-Libs>0:devel/p5-Project-Libs \
	p5-Tie-IxHash>0:devel/p5-Tie-IxHash \
	p5-UNIVERSAL-require>0:devel/p5-UNIVERSAL-require \
	p5-YAML-Tiny-Color>0:textproc/p5-YAML-Tiny-Color
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
