# New ports collection makefile for:	textproc/p5-DelimMatch
# Date created:				28 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	DelimMatch
PORTVERSION=	1.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@tobez.org

PERL_CONFIGURE=	yes

MAN3=		Text::DelimMatch.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-patch:
	@${PERL} -pi -e 's/(\$$match,.*)\$$match,/$$1/' ${WRKSRC}/DelimMatch.pm

.include <bsd.port.mk>
