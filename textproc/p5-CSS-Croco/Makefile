# New ports collection makefile for:  CSS-Croco
# Date created: 26 December 2009
# Whom: andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	CSS-Croco
PORTVERSION=	0.09
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Quick CSS parser

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		libcroco>=0.6:${PORTSDIR}/textproc/libcroco
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.9+
MAN3=	CSS::Croco.3\
	CSS::Croco::Selector.3\
	CSS::Croco::Statement.3\
	CSS::Croco::Statement::Media.3\
	CSS::Croco::Statement::RuleSet.3\
	CSS::Croco::StyleSheet.3\
	CSS::Croco::Term.3\
	CSS::Croco::Term::Hash.3\
	CSS::Croco::Term::Ident.3\
	CSS::Croco::Term::Number.3\
	CSS::Croco::Term::String.3\
	CSS::Croco::Term::URI.3

.include <bsd.port.mk>
