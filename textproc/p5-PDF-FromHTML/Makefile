# New ports collection makefile for:	p5-PDF-FromHTML
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	PDF-FromHTML
PORTVERSION=	0.12
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PDF
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Convert HTML documents to PDF

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Tidy.pm:${PORTSDIR}/textproc/p5-HTML-Tidy \
		${SITE_PERL}/Graphics/ColorNames.pm:${PORTSDIR}/graphics/p5-Graphics-ColorNames \
		${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/PDF/API2.pm:${PORTSDIR}/textproc/p5-PDF-API2 \
		${SITE_PERL}/PDF/Template.pm:${PORTSDIR}/print/p5-PDF-Template \
		${SITE_PERL}/PDF/Writer.pm:${PORTSDIR}/textproc/p5-PDF-Writer \
		${SITE_PERL}/XML/Twig.pm:${PORTSDIR}/textproc/p5-XML-Twig
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		html2pdf.pl.1
MAN3=		PDF::FromHTML.3 PDF::FromHTML::Twig.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
