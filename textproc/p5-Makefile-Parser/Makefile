# New ports collection makefile for:	textproc/p5-Makefile-Parser
# Date created:				11 April 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Makefile-Parser
PORTVERSION=	0.211
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/A/AG/AGENT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Makefile::Parser - A Simple Parser for Makefiles

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Class-Trigger>=0.13:${PORTSDIR}/devel/p5-Class-Trigger \
		p5-Makefile-DOM>=0.003:${PORTSDIR}/textproc/p5-Makefile-DOM

PERL_CONFIGURE=	5.6.1+

MAN1=		makesimple.1 \
		pgmake-db.1 \
		plmake.1
MAN3=		Makefile::AST.3 \
		Makefile::AST::Evaluator.3 \
		Makefile::Parser.3 \
		Makefile::Parser::GmakeDB.3

.include <bsd.port.mk>
