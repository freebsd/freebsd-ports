# New ports collection makefile for:	SRU
# Date created:				23 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SRU
PORTVERSION=	0.93
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/B/BR/BRICAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Search and Retrieval by URL

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/CGI/Application.pm:${PORTSDIR}/www/p5-CGI-Application \
		${SITE_PERL}/CQL/Parser.pm:${PORTSDIR}/textproc/p5-CQL-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Catalyst::Plugin::SRU.3 \
	SRU.3 \
	SRU::Request.3 \
	SRU::Request::Explain.3 \
	SRU::Request::Scan.3 \
	SRU::Request::SearchRetrieve.3 \
	SRU::Response.3 \
	SRU::Response::Diagnostic.3 \
	SRU::Response::Explain.3 \
	SRU::Response::Record.3 \
	SRU::Response::Scan.3 \
	SRU::Response::SearchRetrieve.3 \
	SRU::Response::Term.3 \
	SRU::Server.3 \
	SRU::Utils.3 \
	SRU::Utils::XML.3 \
	SRU::Utils::XMLTest.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl5.6
.endif

.include <bsd.port.post.mk>
