# New ports collection makefile for:	p5-Text-BibTeX
# Date created:				Mon Jan 19 2003
# Whom:					David Bremner <bremner@unb.ca>
#
# $FreeBSD$
#

PORTNAME=	Text-BibTeX
PORTVERSION=	0.36
PORTREVISION=	0
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:C/$/:text,btparse/g}
MASTER_SITE_SUBDIR=	../by-authors/id/A/AM/AMBS/Text/:text \
			../by-authors/id/A/AM/AMBS/btparse/:btparse
PKGNAMEPREFIX=	p5-
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:text \
		btparse-${BTPARSE_VER}${EXTRACT_SUFX}:btparse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manipulate BibTeX files from perl

BTPARSE_VER=	0.35

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
