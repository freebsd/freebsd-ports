# New ports collection makefile for:	textproc/p5-Pod-Elemental
# Date created:				May 26, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pod-Elemental
PORTVERSION=	0.101620
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Treating a Pod documents as trees of elements

BUILD_DEPENDS=	p5-Pod-Eventual>=0:${PORTSDIR}/textproc/p5-Pod-Eventual \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Moose-Autobox>=0.10:${PORTSDIR}/devel/p5-Moose-Autobox \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-String-RewritePrefix>=0:${PORTSDIR}/textproc/p5-String-RewritePrefix \
		p5-String-Truncate>=0:${PORTSDIR}/textproc/p5-String-Truncate \
		p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Sub-Exporter-ForMethods>=0:${PORTSDIR}/devel/p5-Sub-Exporter-ForMethods
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Pod::Elemental.3 \
		Pod::Elemental::Autoblank.3 \
		Pod::Elemental::Autochomp.3 \
		Pod::Elemental::Command.3 \
		Pod::Elemental::Document.3 \
		Pod::Elemental::Element::Generic::Blank.3 \
		Pod::Elemental::Element::Generic::Command.3 \
		Pod::Elemental::Element::Generic::Nonpod.3 \
		Pod::Elemental::Element::Generic::Text.3 \
		Pod::Elemental::Element::Nested.3 \
		Pod::Elemental::Element::Pod5::Command.3 \
		Pod::Elemental::Element::Pod5::Data.3 \
		Pod::Elemental::Element::Pod5::Nonpod.3 \
		Pod::Elemental::Element::Pod5::Ordinary.3 \
		Pod::Elemental::Element::Pod5::Region.3 \
		Pod::Elemental::Element::Pod5::Verbatim.3 \
		Pod::Elemental::Flat.3 \
		Pod::Elemental::Node.3 \
		Pod::Elemental::Objectifier.3 \
		Pod::Elemental::Paragraph.3 \
		Pod::Elemental::Selectors.3 \
		Pod::Elemental::Transformer.3 \
		Pod::Elemental::Transformer::Gatherer.3 \
		Pod::Elemental::Transformer::Nester.3 \
		Pod::Elemental::Transformer::Pod5.3 \
		Pod::Elemental::Types.3

.include <bsd.port.mk>
