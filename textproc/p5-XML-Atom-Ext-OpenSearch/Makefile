# New ports collection makefile for:	p5-XML-Atom-Ext-OpenSearch
# Date created:	   27 Oct 2008
# Whom:		   Denis Pokataev <catone@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Atom-Ext-OpenSearch
PORTVERSION=	0.02
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	XML::Atom extension for OpenSearch data

BUILD_DEPENDS=	${SITE_PERL}/XML/Atom.pm:${PORTSDIR}/textproc/p5-XML-Atom
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Atom::Ext::OpenSearch.3 \
	XML::Atom::Ext::OpenSearch::Query.3

.include <bsd.port.mk>
