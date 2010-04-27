# New ports collection makefile for:	p5-Text-NSP
# Date created:				Sep 30 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Text-NSP
PORTVERSION=	1.17
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl5 modules for Ngram Statistics Package

PERL_CONFIGURE=	5.8.0+

MAN1=	combig.pl.1 count.pl.1 \
	count2huge.pl.1 \
	huge-count.pl.1 \
	huge-delete.pl.1 huge-split.pl.1 \
	huge-merge.pl.1 huge-sort.pl.1 \
	kocos.pl.1 rank.pl.1 \
	statistic.pl.1
MAN3=	Text::NSP.3 \
	Text::NSP::Measures.3 \
	Text::NSP::Measures::2D.3 \
	Text::NSP::Measures::2D::CHI.3 \
	Text::NSP::Measures::2D::CHI::phi.3 \
	Text::NSP::Measures::2D::CHI::tscore.3 \
	Text::NSP::Measures::2D::CHI::x2.3 \
	Text::NSP::Measures::2D::Dice.3 \
	Text::NSP::Measures::2D::Dice::dice.3 \
	Text::NSP::Measures::2D::Dice::jaccard.3 \
	Text::NSP::Measures::2D::Fisher.3 \
	Text::NSP::Measures::2D::Fisher2.3 \
	Text::NSP::Measures::2D::Fisher2::left.3 \
	Text::NSP::Measures::2D::Fisher2::right.3 \
	Text::NSP::Measures::2D::Fisher2::twotailed.3 \
	Text::NSP::Measures::2D::Fisher::left.3 \
	Text::NSP::Measures::2D::Fisher::right.3 \
	Text::NSP::Measures::2D::Fisher::twotailed.3 \
	Text::NSP::Measures::2D::MI.3 \
	Text::NSP::Measures::2D::MI::ll.3 \
	Text::NSP::Measures::2D::MI::pmi.3 \
	Text::NSP::Measures::2D::MI::ps.3 \
	Text::NSP::Measures::2D::MI::tmi.3 \
	Text::NSP::Measures::2D::odds.3 \
	Text::NSP::Measures::3D.3 \
	Text::NSP::Measures::3D::MI.3 \
	Text::NSP::Measures::3D::MI::ll.3 \
	Text::NSP::Measures::3D::MI::pmi.3 \
	Text::NSP::Measures::3D::MI::ps.3 \
	Text::NSP::Measures::3D::MI::tmi.3 \
	Text::NSP::Measures::4D.3 \
	Text::NSP::Measures::4D::MI.3 \
	Text::NSP::Measures::4D::MI::ll.3

DOCS=	CHANGES README doc/FAQ.pod doc/NSP-Class-diagram.pdf \
	doc/NSP-Class-diagram.png doc/README.pod doc/TODO.pod \
	doc/USAGE.pod doc/cicling2003.pdf doc/cicling2003.ps \

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===>   Installing documentation in ${DOCSDIR}"
.endif

.include <bsd.port.mk>
