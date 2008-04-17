# New ports collection makefile for:	p5-Text-Markdown-ApacheHandler
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Markdown-ApacheHandler
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Processes files with Markdown syntax for Apache

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache/Constants.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/Apache/File.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/Text/Markdown.pm:${PORTSDIR}/textproc/p5-Text-Markdown

PERL_CONFIGURE=	yes

MAN3=		Text::Markdown::ApacheHandler.3

.include <bsd.port.mk>
