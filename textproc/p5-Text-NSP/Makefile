# New ports collection makefile for:	p5-Text-NSP
# Date created:				Sep 30 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Text-NSP
PORTVERSION=	0.95
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl5 modules for Ngram Statistics Package

PERL_CONFIGURE=	yes
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

MAN1=	combig.pl.1 count.pl.1 \
	huge-combine.pl.1 huge-count.pl.1 \
	kocos.pl.1 rank.pl.1 \
	sort-bigrams.pl.1 split-data.pl.1 statistic.pl.1

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
	Text::NSP::Measures::3D::MI::tmi.3

post-patch:
	@${REINPLACE_CMD} -e \
	's,$(SITEPREFIX)/doc,$(SITEPREFIX)/share/doc/${PKGNAMEPREFIX}${PORTNAME},' \
	${WRKSRC}/Makefile.PL
	@${FIND} ${WRKSRC} -name "*.pl" |${XARGS} \
	${REINPLACE_CMD} -e 's|/usr/local/bin/perl|/usr/bin/env perl|'
	@${FIND} ${WRKSRC} -name "*.p[lm]" |${XARGS} \
	${REINPLACE_CMD} -e 's|split.*(/:/, $$ENV{PATH})|@INC|'
	@${FIND} ${WRKSRC} -name "*.bak" | ${XARGS} ${RM}

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%DOCSDIR%%:${DOCSDIR}:g"

.if defined(NOPORTDOCS)
pre-patch:
	@${REINPLACE_CMD} -e \
	"s,'html',''," ${WRKSRC}/Makefile.PL
.endif
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
