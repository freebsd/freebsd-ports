# New ports collection makefile for:	textproc/p5-Text-WordDiff
# Date created:				28 January 2006
# Whom:					Rod Taylor <ports@rbt.ca>
#
# $FreeBSD$
#

PORTNAME=	Text-WordDiff
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@rbt.ca
COMMENT=	Text::WordDiff - Track changes between documents

PERL_BUILD_DEPENDS=	Test-Simple:${PORTSDIR}/devel/p5-Test-Simple
PERL_RUN_DEPENDS=	Algorithm-Diff:${PORTSDIR}/devel/p5-Algorithm-Diff \
			Term-ANSIColor:${PORTSDIR}/devel/p5-Term-ANSIColor \
			HTML-Entities:${PORTSDIR}/www/p5-HTML-Parser

PERL_MODBUILD=	yes

MAN3=		Text::WordDiff.3 Text::WordDiff::ANSIColor.3 Text::WordDiff::HTML.3

.include <bsd.port.mk>
