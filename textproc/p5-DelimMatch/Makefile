# New ports collection makefile for:	textproc/p5-DelimMatch
# Date created:				28 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	DelimMatch
PORTVERSION=	1.04
CATEGORIES=	textproc perl5
MASTER_SITES=	http://nwalsh.com/perl/delimmatch/
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3=		Text::DelimMatch.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-patch:
	${MV} ${WRKSRC}/DelimMatch.pm ${WRKSRC}/DelimMatch.pm.old
	${TR} -d "[\r]" < ${WRKSRC}/DelimMatch.pm.old > ${WRKSRC}/DelimMatch.pm

.include <bsd.port.mk>
