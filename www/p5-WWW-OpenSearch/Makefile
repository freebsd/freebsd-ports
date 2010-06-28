# New ports collection makefile for:	p5-WWW-OpenSearch
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-OpenSearch
PORTVERSION=	0.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	Search A9 OpenSearch compatible engines

RUN_DEPENDS=	${SITE_PERL}/URI/Template.pm:${PORTSDIR}/net/p5-URI-Template \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Data-Page>=2.00:${PORTSDIR}/databases/p5-Data-Page \
		p5-XML-Feed>=0.08:${PORTSDIR}/textproc/p5-XML-Feed \
		p5-libwww>=5.60:${PORTSDIR}/www/p5-libwww \
		p5-XML-LibXML>=1.58:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::OpenSearch.3 \
		WWW::OpenSearch::Agent.3 \
		WWW::OpenSearch::Description.3 \
		WWW::OpenSearch::Image.3 \
		WWW::OpenSearch::Query.3 \
		WWW::OpenSearch::Response.3 \
		WWW::OpenSearch::Request.3 \
		WWW::OpenSearch::Url.3

.include <bsd.port.mk>
