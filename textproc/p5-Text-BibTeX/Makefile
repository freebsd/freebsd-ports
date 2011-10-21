# New ports collection makefile for:	p5-Text-BibTeX
# Date created:				Mon Jan 19 2003
# Whom:					David Bremner <bremner@unb.ca>
#
# $FreeBSD$
#

PORTNAME=	Text-BibTeX
PORTVERSION=	0.61
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AMBS/Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate BibTeX files from perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-AutoConf>=0.16:${PORTSDIR}/devel/p5-Config-AutoConf \
		p5-ExtUtils-LibBuilder>0.02:${PORTSDIR}/devel/p5-ExtUtils-LibBuilder
TEST_DEPENDS=	p5-Capture-Tiny>=0.06:${PORTSDIR}/devel/p5-Capture-Tiny

PERL_MODBUILD=	yes
USE_LDCONFIG=	yes

MAN1=		bt_format_names.1 bt_input.1 bt_language.1 \
		bt_macros.1 bt_misc.1 bt_post_processing.1 \
		bt_postprocess.1 bt_split_names.1 bt_traversal.1 \
		btool_faq.1 btparse.1

MAN3=		Text::BibTeX.3 \
		Text::BibTeX::Bib.3 \
		Text::BibTeX::BibFormat.3 \
		Text::BibTeX::BibSort.3 \
		Text::BibTeX::Entry.3 \
		Text::BibTeX::File.3 \
		Text::BibTeX::Name.3 \
		Text::BibTeX::NameFormat.3 \
		Text::BibTeX::Structure.3 \
		Text::BibTeX::Value.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
