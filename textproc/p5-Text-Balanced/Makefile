# New ports collection makefile for:	devel/p5-Text-Balanced
# Date created:				16 Sep 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Balanced
PORTVERSION=	2.0.0
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extract delimited text sequences from strings

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version

PERL_CONFIGURE=	yes

MAN3=		Text::Balanced.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600 # from p5-version
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
