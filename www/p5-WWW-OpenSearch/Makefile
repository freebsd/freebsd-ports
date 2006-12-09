# New ports collection makefile for:	p5-WWW-OpenSearch
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-OpenSearch
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search A9 OpenSearch compatible engines

RUN_DEPENDS=	p5-Data-Page>=2.00:${PORTSDIR}/databases/p5-Data-Page \
		p5-libwww>=5.60:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		p5-XML-Feed>=0.08:${PORTSDIR}/textproc/p5-XML-Feed \
		p5-XML-LibXML>=1.58:${PORTSDIR}/textproc/p5-XML-LibXML

PERL_CONFIGURE=	yes

MAN3=		WWW::OpenSearch.3 \
		WWW::OpenSearch::Description.3 \
		WWW::OpenSearch::Image.3 \
		WWW::OpenSearch::Query.3 \
		WWW::OpenSearch::Response.3 \
		WWW::OpenSearch::Url.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500701
IGNORE=		requires perl 5.7.1 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
