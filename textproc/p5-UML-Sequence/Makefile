# New ports collection makefile for:	p5-UML-Sequence
# Date created:				October 15th 2003
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	UML-Sequence
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	UML
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A perl module that produce UML sequence diagrams

BUILD_DEPENDS=	${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM \
		${SITE_PERL}/GD/Text.pm:${PORTSDIR}/graphics/p5-GD-TextUtil
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		seq2svg.pl.1 genericseq.pl.1 seq2rast.pl.1
MAN3=		UML::Sequence.3 \
		UML::Sequence::SimpleSeq.3 \
		UML::Sequence::Activation.3 \
		UML::Sequence::Raster.3 \
		UML::seq2rast.3 \
		UML::seq2svg.3 \
		UML::Sequence::PerlSeq.3 \
		UML::Sequence::JavaSeq.3 \
		UML::genericseq.3 \
		Devel::OOCallSeq.3 \
		UML::Sequence::PerlOOSeq.3 \
		UML::Sequence::Svg.3 \
		Devel::CallSeq.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
