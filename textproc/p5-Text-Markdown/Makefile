# New ports collection makefile for:	p5-Text-Markdown
# Date created:				20.Mar.2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Text-Markdown
PORTVERSION=	1.000031
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Markdown Perl5 module

BUILD_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-ExtUtils-MakeMaker>=6.42:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
RUN_DEPENDS=${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=		Markdown.pl.1
MAN3=		Text::Markdown.3

.include <bsd.port.mk>
