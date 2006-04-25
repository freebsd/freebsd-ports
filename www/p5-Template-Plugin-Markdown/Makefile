# New ports collection makefile for:	www/p5-Template-Plugin-Markdown
# Date created:				24 Apr 2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-Markdown
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	TT plugin for Text::Markdown

BUILD_DEPENDS=	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Text-Markdown>=0:${PORTSDIR}/textproc/p5-Text-Markdown
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Template::Plugin::Markdown.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6 or newer. Please install lang/perl5 or lang/perl5.6 and try again
.endif
.include <bsd.port.post.mk>
