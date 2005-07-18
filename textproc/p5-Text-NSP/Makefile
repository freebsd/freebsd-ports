# New ports collection makefile for:	p5-Text-NSP
# Date created:				Sep 30 2004
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Text-NSP
PORTVERSION=	0.71
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
MAN3=	pmi.3 rightFisher.3 measure3d.3 \
	tmi.3 leftFisher.3 measure2d.3 \
	odds.3 ll.3 ll3.3 dice.3 x2.3 \
	phi.3 tscore.3 tmi3.3

post-patch:
	@${REINPLACE_CMD} -e \
	's,$(SITEPREFIX)/doc,$(SITEPREFIX)/share/doc/${PKGNAMEPREFIX}${PORTNAME},' \
	${WRKSRC}/Makefile.PL
	@${FIND} ${WRKSRC} -name "*.pl" |${XARGS} \
	${REINPLACE_CMD} -e 's|/usr/local/bin/perl|/usr/bin/env perl|'
	@${FIND} ${WRKSRC} -name "*.p[lm]" |${XARGS} \
	${REINPLACE_CMD} -e 's|split.*(/:/, $$ENV{PATH})|@INC|'

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%DOCSDIR%%:${DOCSDIR}:g"

.if defined(NOPORTDOCS)
pre-patch:
	@${REINPLACE_CMD} -e \
	"s,'html',''," ${WRKSRC}/Makefile.PL
.endif
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	This port requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
