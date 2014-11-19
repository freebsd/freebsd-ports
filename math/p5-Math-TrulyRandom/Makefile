# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-TrulyRandom
PORTVERSION=	1.0
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to a truly random number generator function

LICENSE=	BSD3CLAUSE

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/truerand.c ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/truerand.h ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Math/TrulyRandom/TrulyRandom.so

.include <bsd.port.mk>
