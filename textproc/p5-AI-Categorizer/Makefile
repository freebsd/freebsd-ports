# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AI-Categorizer
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic Text Categorization

BUILD_DEPENDS=	p5-Class-Container>=0:${PORTSDIR}/devel/p5-Class-Container \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Statistics-Contingency>=0:${PORTSDIR}/math/p5-Statistics-Contingency \
		p5-Lingua-Stem>=0:${PORTSDIR}/textproc/p5-Lingua-Stem \
		p5-Time-Progress>=0:${PORTSDIR}/devel/p5-Time-Progress \
		p5-Algorithm-SVM>=0:${PORTSDIR}/devel/p5-Algorithm-SVM \
		p5-AI-DecisionTree>=0:${PORTSDIR}/math/p5-AI-DecisionTree \
		p5-Algorithm-NaiveBayes>=0:${PORTSDIR}/devel/p5-Algorithm-NaiveBayes
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	AI::Categorizer.3 \
	AI::Categorizer::Category.3 \
	AI::Categorizer::Collection.3 \
	AI::Categorizer::Collection::Files.3 \
	AI::Categorizer::Document.3 \
	AI::Categorizer::Experiment.3 \
	AI::Categorizer::FeatureSelector.3 \
	AI::Categorizer::FeatureSelector::CategorySelector.3 \
	AI::Categorizer::FeatureSelector::ChiSquare.3 \
	AI::Categorizer::FeatureSelector::DocFrequency.3 \
	AI::Categorizer::FeatureVector.3 \
	AI::Categorizer::Hypothesis.3 \
	AI::Categorizer::KnowledgeSet.3 \
	AI::Categorizer::Learner.3 \
	AI::Categorizer::Learner::Boolean.3 \
	AI::Categorizer::Learner::DecisionTree.3 \
	AI::Categorizer::Learner::Guesser.3 \
	AI::Categorizer::Learner::KNN.3 \
	AI::Categorizer::Learner::NaiveBayes.3 \
	AI::Categorizer::Learner::SVM.3 \
	AI::Categorizer::Learner::Weka.3 \
	AI::Categorizer::Storable.3

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
