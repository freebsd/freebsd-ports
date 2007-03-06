# New ports collection makefile for:	p5-Text-Hatena
# Date created:		2006-07-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Hatena
PORTVERSION=	0.20
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for formatting text with Hatena Style

RUN_DEPENDS=	p5-Parse-RecDescent>=1.94:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Regexp-Assemble>=0.28:${PORTSDIR}/devel/p5-Regexp-Assemble
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::Hatena.3 Text::Hatena::AutoLink.3

.include <bsd.port.mk>
