# New ports collection makefile for:	www/p5-URI-Sequin
# Date created:				25 April 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	URI-Sequin
PORTVERSION=	1.2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/S/SA/SARGIE
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Extract information from the URLs of Search-Engines

PERL_CONFIGURE=	yes

MAN3=		URI::Sequin.3

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/URI/Sequin/examples
	@${INSTALL_DATA} ${WRKSRC}/example.pl ${WRKSRC}/ref?.log \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/URI/Sequin/examples
.endif

.include <bsd.port.mk>
