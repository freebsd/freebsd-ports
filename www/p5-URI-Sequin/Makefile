# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	URI-Sequin
PORTVERSION=	1.2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SARGIE
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Extract information from the URLs of Search-Engines

USES=		perl5
USE_PERL5=	configure

MAN3=		URI::Sequin.3

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/${SITE_PERL_REL}/URI/Sequin/examples
	@${INSTALL_DATA} ${WRKSRC}/example.pl ${WRKSRC}/ref?.log \
		${PREFIX}/${SITE_PERL_REL}/URI/Sequin/examples
.endif

.include <bsd.port.mk>
