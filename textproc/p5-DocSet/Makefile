# New ports collection makefile for:	p5-DocSet
# Date created:				2009 January 14
# Whom:					pgollucci@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	DocSet
PORTVERSION=	0.19
CATEGORIES=	textproc www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/ST/STAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Dcumentation projects builder in HTML, PS and PDF formats

BUILD_DEPENDS=	${SITE_PERL}/Pod/POM.pm:${PORTSDIR}/textproc/p5-Pod-POM \
				${SITE_PERL}/${PERL_ARCH}/Template/Toolkit.pod:${PORTSDIR}/www/p5-Template-Toolkit

MAKE_JOBS_SAFE=  yes

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

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
