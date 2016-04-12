# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Text-SpellChecker-GUI
PORTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Implements a user interface to Text::SpellChecker using ZConf::GUI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Curses-UI>=0:devel/p5-Curses-UI \
		p5-String-ShellQuote>=0:textproc/p5-String-ShellQuote \
		p5-ZConf-GUI>=0:devel/p5-ZConf-GUI \
		p5-Text-SpellChecker>=0:textproc/p5-Text-SpellChecker

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/curses-textspellchecker bin/textspellchecker
USE_PERL5=	configure

.include <bsd.port.mk>
