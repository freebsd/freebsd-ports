# New ports collection makefile for:	math/p5-AI-DecisionTree
# Date created:				Dec 29 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	AI-DecisionTree
PORTVERSION=	0.08
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	AI
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl module for Automatically Learning Decision Trees

PERL_CONFIGURE=	yes

MAN3=		AI::DecisionTree.3 \
		AI::DecisionTree::Instance.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
