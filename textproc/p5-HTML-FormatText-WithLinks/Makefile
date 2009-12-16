# New ports collection makefile for:	p5-HTML-FormatText-WithLinks
# Date created:		2007-08-10
# Whom:			loader <loader@freebsdmall.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-FormatText-WithLinks
PORTVERSION=	0.11
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	loader@freebsdmall.com
COMMENT=	Perl5 module to convert HTML to text with links as footnotes

BUILD_DEPENDS=	${SITE_PERL}/HTML/FormatText.pm:${PORTSDIR}/textproc/p5-HTML-Format
RUN_DEPENDS=	${SITE_PERL}/HTML/FormatText.pm:${PORTSDIR}/textproc/p5-HTML-Format

PERL_CONFIGURE=	yes
MAN3=		HTML::FormatText::WithLinks.3

.include <bsd.port.mk>
