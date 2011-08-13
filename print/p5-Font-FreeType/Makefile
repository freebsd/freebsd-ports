# New ports collection makefile for:	Font::FreeType
# Date created:		12 Aug 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Font-FreeType
PORTVERSION=	0.03
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to read font files and render glyphs using FreeType2

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

PERL_CONFIGURE=	yes

MAN3=	Font::FreeType.3 \
	Font::FreeType::Face.3 \
	Font::FreeType::Glyph.3

.include <bsd.port.mk>
