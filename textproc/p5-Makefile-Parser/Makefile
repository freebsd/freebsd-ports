# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Makefile-Parser
PORTVERSION=	0.215
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AGENT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Makefile::Parser - A Simple Parser for Makefiles

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Trigger>=0.13:${PORTSDIR}/devel/p5-Class-Trigger \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-IPC-Run3>=0.036:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Makefile-DOM>=0.005:${PORTSDIR}/textproc/p5-Makefile-DOM
RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Trigger>=0.13:${PORTSDIR}/devel/p5-Class-Trigger \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Makefile-DOM>=0.005:${PORTSDIR}/textproc/p5-Makefile-DOM

USES=		perl5
USE_PERL5=	configure

MAN1=		makesimple.1 \
		pgmake-db.1 \
		plmake.1
MAN3=		Makefile::AST.3 \
		Makefile::AST::Evaluator.3 \
		Makefile::Parser.3 \
		Makefile::Parser::GmakeDB.3

.include <bsd.port.mk>
