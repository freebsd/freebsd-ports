# New ports collection makefile for:	p5-Text-Bastardize
# Date created:		26 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Bastardize
DISTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Corruptor of innocent text

PERL_CONFIGURE=	YES

MAN3=		Text::Bastardize.3

PLIST_FILES=	%%SITE_PERL%%/Text/Bastardize.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Text/Bastardize/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Text/Bastardize

.include <bsd.port.mk>
