# New ports collection makefile for:	textproc/p5-Text-Diff
# Date created:				14 July 2002
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Diff
PORTVERSION=	1.37
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Text::Diff - Perform diffs on files and record sets

BUILD_DEPENDS=	${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::Diff.3 Text::Diff::Table.3

.include <bsd.port.mk>
