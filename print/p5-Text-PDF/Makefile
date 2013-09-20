# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Text-PDF
PORTVERSION=	0.29a
PORTREVISION=	2
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	A PDF manipulation module

WRKSRC=		${WRKDIR}/${DISTNAME:C/a$//}

USES=		perl5
USE_PERL5=	configure

MAN3=		Text::PDF::Pages.3 Text::PDF::Page.3 Text::PDF::Name.3 \
		Text::PDF::TTFont0.3 Text::PDF::String.3 Text::PDF::File.3 \
		Text::PDF::Dict.3 Text::PDF::Array.3 Text::PDF::Bool.3 \
		Text::PDF::Objind.3 Text::PDF::SFont.3 Text::PDF::Filter.3 \
		Text::PDF::Utils.3 Text::PDF::TTFont.3 Text::PDF::Number.3 \
		Text::PDF::Null.3 Text::PDF.3

NO_STAGE=	yes
post-patch:
	@${RM} -f ${WRKSRC}/pm_to_blib

post-install:
	@${MKDIR} ${SITE_PERL}/Text/PDF/examples
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${SITE_PERL}/Text/PDF/examples

.include <bsd.port.mk>
