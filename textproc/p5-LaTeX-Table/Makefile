# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	LaTeX-Table
PORTVERSION=	1.0.6
PORTREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the automatic generation of LaTeX tables

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.76:devel/p5-Moose \
		p5-Moose-Policy>=0:devel/p5-Moose-Policy \
		p5-LaTeX-Encode>=0:textproc/p5-LaTeX-Encode \
		p5-LaTeX-Driver>=0:textproc/p5-LaTeX-Driver \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-Number-Format>=0:textproc/p5-Number-Format \
		p5-MooseX-FollowPBP>=0.03:devel/p5-MooseX-FollowPBP
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-NoWarnings>=0.084:devel/p5-Test-NoWarnings

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
