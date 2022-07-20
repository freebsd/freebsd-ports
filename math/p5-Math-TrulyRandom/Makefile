PORTNAME=	Math-TrulyRandom
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to a truly random number generator function

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/truerand.c ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/truerand.h ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/TrulyRandom/TrulyRandom.so

.include <bsd.port.mk>
