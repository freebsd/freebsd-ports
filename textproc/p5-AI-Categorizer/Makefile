# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AI-Categorizer
PORTVERSION=	0.09
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatic Text Categorization

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Container>=0:devel/p5-Class-Container \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Statistics-Contingency>=0:math/p5-Statistics-Contingency \
		p5-Lingua-Stem>=0:textproc/p5-Lingua-Stem \
		p5-Time-Progress>=0:devel/p5-Time-Progress \
		p5-Algorithm-SVM>=0:devel/p5-Algorithm-SVM \
		p5-AI-DecisionTree>=0:math/p5-AI-DecisionTree \
		p5-Algorithm-NaiveBayes>=0:devel/p5-Algorithm-NaiveBayes
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
