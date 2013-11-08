# $FreeBSD$

PORTNAME=	Text-LTSV
PORTVERSION=	0.07
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Labeled Tab Separated Value manipulator

RUN_DEPENDS=	\
	p5-Project-Libs>0:${PORTSDIR}/devel/p5-Project-Libs \
	p5-Tie-IxHash>0:${PORTSDIR}/devel/p5-Tie-IxHash \
	p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
	p5-YAML-Tiny-Color>0:${PORTSDIR}/textproc/p5-YAML-Tiny-Color
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
