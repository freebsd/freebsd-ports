# New ports collection makefile for:	Math::TrulyRandom
# Date created:				17 March 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-TrulyRandom
PORTVERSION=	1.0
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	anders@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3=		Math::TrulyRandom.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/truerand.c ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/truerand.h ${DOCSDIR}/
.endif

.include <bsd.port.mk>
