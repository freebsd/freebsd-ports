# New ports collection makefile for:	www/p5-Template-Plugin-Markdown
# Date created:				24 Apr 2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-Markdown
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	TT plugin for Text::Markdown

BUILD_DEPENDS=	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Text-Markdown>=0:${PORTSDIR}/textproc/p5-Text-Markdown
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Template::Plugin::Markdown.3

.include <bsd.port.mk>
