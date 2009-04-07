# New ports collection makefile for:	textproc/p5-Text-WordDiff
# Date created:				28 January 2006
# Whom:					Rod Taylor <ports@rbt.ca>
#
# $FreeBSD$
#

PORTNAME=	Text-WordDiff
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Track changes between documents

RUN_DEPENDS=	${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser

PERL_MODBUILD=	yes

MAN3=		Text::WordDiff.3 Text::WordDiff::ANSIColor.3 Text::WordDiff::HTML.3

.include <bsd.port.mk>
