# New ports collection makefile for:	print/p5-Text-PDF
# Date created:				30 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Text-PDF
PORTVERSION=	0.29a
PORTREVISION=	1
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A PDF manipulation module

WRKSRC=		${WRKDIR}/${DISTNAME:C/a$//}

PERL_CONFIGURE=	yes

MAN3=		Text::PDF::Pages.3 Text::PDF::Page.3 Text::PDF::Name.3 \
		Text::PDF::TTFont0.3 Text::PDF::String.3 Text::PDF::File.3 \
		Text::PDF::Dict.3 Text::PDF::Array.3 Text::PDF::Bool.3 \
		Text::PDF::Objind.3 Text::PDF::SFont.3 Text::PDF::Filter.3 \
		Text::PDF::Utils.3 Text::PDF::TTFont.3 Text::PDF::Number.3 \
		Text::PDF::Null.3 Text::PDF.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
BUILD_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

post-patch:
	@${RM} -f ${WRKSRC}/pm_to_blib

post-install:
	@${MKDIR} ${SITE_PERL}/Text/PDF/examples
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${SITE_PERL}/Text/PDF/examples

.include <bsd.port.post.mk>
