# New ports collection makefile for:	print/p5-Text-PDF
# Date created:				30 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Text-PDF
PORTVERSION=	0.13
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@tobez.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::PDF::Pages.3 Text::PDF::Page.3 Text::PDF::Name.3 \
		Text::PDF::TTFont0.3 Text::PDF::String.3 Text::PDF::File.3 \
		Text::PDF::Dict.3 Text::PDF::Array.3 Text::PDF::Bool.3 \
		Text::PDF::Objind.3 Text::PDF::SFont.3 Text::PDF::Filter.3 \
		Text::PDF::Utils.3 Text::PDF::TTFont.3 Text::PDF::Number.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-install:
	@${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Text/PDF/examples
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Text/PDF/examples

.include <bsd.port.mk>
