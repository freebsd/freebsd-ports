# New ports collection makefile for:	p5-Text-BibTeX
# Date created:				Mon Jan 19 2003
# Whom:					David Bremner <bremner@unb.ca>
#
# $FreeBSD$
#

PORTNAME=	Text-BibTeX
PORTVERSION=	0.34
PORTREVISION=	1

CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	biblio/bibtex/utils/btOOL
PKGNAMEPREFIX=	p5-
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz btparse-0.33.tar.gz

MAINTAINER=	bremner@unb.ca
COMMENT=	Text::BibTeX - Manipulate BibTeX files from perl

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN3=		Text::BibTeX.3 \
		Text::BibTeX::Bib.3 \
		Text::BibTeX::BibFormat.3 \
		Text::BibTeX::BibSort.3 \
		Text::BibTeX::Entry.3 \
		Text::BibTeX::File.3 \
		Text::BibTeX::Name.3 \
		Text::BibTeX::NameFormat.3 \
		Text::BibTeX::Structure.3 \
		Text::BibTeX::Value.3 \
		btool_faq.3

.include <bsd.port.mk>
