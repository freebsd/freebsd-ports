# New ports collection makefile for:	p5-NNTPClient
# Date created:				1st June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	NNTPClient
PORTVERSION=	0.36
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	News
PKGNAMEPREFIX=	p5-

MAINTAINER=	ade@FreeBSD.org

USE_PERL5=	yes

MAN3=		News::NNTPClient.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
