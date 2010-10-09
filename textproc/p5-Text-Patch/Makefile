# New ports collection makefile for:	Text::Patch
# Date created:		20 Dec 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Patch
PORTVERSION=	1.8
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to patch text with given patch

RUN_DEPENDS=	p5-Text-Diff>0:${PORTSDIR}/textproc/p5-Text-Diff
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Text::Patch.3

.include <bsd.port.mk>
