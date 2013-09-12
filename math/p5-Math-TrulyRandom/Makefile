# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-TrulyRandom
PORTVERSION=	1.0
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Perl interface to a truly random number generator function

USES=		perl5
USE_PERL5=	configure

MAN3=		Math::TrulyRandom.3

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/truerand.c ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/truerand.h ${DOCSDIR}/
.endif

.include <bsd.port.mk>
