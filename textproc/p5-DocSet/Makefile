# $FreeBSD$

PORTNAME=	DocSet
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Documentation projects builder in HTML, PS, and PDF formats

BUILD_DEPENDS=	p5-Pod-POM>=0:${PORTSDIR}/textproc/p5-Pod-POM \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit

MAN1=	docset_build.1

MAN3=	DocSet.3 \
	DocSet::5005compat.3 \
	DocSet::Cache.3 \
	DocSet::Config.3 \
	DocSet::Doc.3 \
	DocSet::Doc::Common.3 \
	DocSet::Doc::HTML2HTML.3 \
	DocSet::Doc::HTML2HTMLPS.3 \
	DocSet::Doc::POD2HTML.3 \
	DocSet::Doc::POD2HTMLPS.3 \
	DocSet::Doc::Text2HTML.3 \
	DocSet::DocSet.3 \
	DocSet::DocSet::HTML.3 \
	DocSet::NavigateCache.3 \
	DocSet::RunTime.3 \
	DocSet::Source::HTML.3 \
	DocSet::Source::POD.3 \
	DocSet::Source::Text.3 \
	DocSet::DocSet::PSPDF.3 \
	DocSet::Util.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
