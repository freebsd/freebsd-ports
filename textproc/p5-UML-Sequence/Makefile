# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	UML-Sequence
PORTVERSION=	0.08
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that produce UML sequence diagrams

RUN_DEPENDS=	p5-XML-DOM>=1.25:${PORTSDIR}/textproc/p5-XML-DOM \
		p5-GD>=2.30:${PORTSDIR}/graphics/p5-GD \
		p5-GD-TextUtil>=0.86:${PORTSDIR}/graphics/p5-GD-TextUtil

USES=		perl5
USE_PERL5=	configure

MAN1=		seq2svg.pl.1 genericseq.pl.1 seq2rast.pl.1
MAN3=	Devel::CallSeq.3 Devel::OOCallSeq.3 \
	UML::Sequence.3 UML::Sequence::Activation.3 \
	UML::Sequence::JavaSeq.3 UML::Sequence::PerlOOSeq.3 \
	UML::Sequence::PerlSeq.3 UML::Sequence::Raster.3 \
	UML::Sequence::SimpleSeq.3 UML::Sequence::Svg.3 \
	UML::genericseq.3 UML::seq2rast.3 \
	UML::seq2svg.3

.include <bsd.port.mk>
