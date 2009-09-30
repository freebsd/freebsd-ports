# New ports collection makefile for:	p5-Text-SpellChecker-GUI
# Date created:		2009-09-27
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Text-SpellChecker-GUI
PORTVERSION=	0.0.1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Implements a user interface to Text::SpellChecker using ZConf::GUI

BUILD_DEPENDS=	${SITE_PERL}/Curses/UI.pm:${PORTSDIR}/devel/p5-Curses-UI \
		${SITE_PERL}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote \
		${SITE_PERL}/ZConf/GUI.pm:${PORTSDIR}/devel/p5-ZConf-GUI \
		${SITE_PERL}/Text/SpellChecker.pm:${PORTSDIR}/textproc/p5-Text-SpellChecker

PERL_CONFIGURE=	yes

MAN3=		Text::SpellChecker::GUI.3 \
		Text::SpellChecker::GUI::Curses.3

.include <bsd.port.mk>
