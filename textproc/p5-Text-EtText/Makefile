# New ports collection makefile for:	p5-HTML-Parser
# Date created: 			21 June 2002
# Whom:					Joseph Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	Text-EtText
PORTVERSION=	2.2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	A simple plain-text to HTML converter

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Text::EtText.3 Text::EtText::DefaultGlossary.3 \
		Text::EtText::LinkGlossary.3 Text::EtText::EtText2HTML.3 \
		Text::EtText::HTML2EtText.3
MAN1=		ethtml2text.1 ettext2html.1

.include <bsd.port.mk>
