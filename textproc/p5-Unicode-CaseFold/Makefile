# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Unicode-CaseFold
PORTVERSION=	1.00
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ARODLAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Unicode case-folding for case-insensitive lookups

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	modbuild

PLIST_FILES=	%%SITE_PERL%%/%%PERL_ARCH%%/Unicode/CaseFold.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/Unicode/CaseFoldPP.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Unicode/CaseFold/CaseFold.so \
		%%PERL5_MAN3%%/Unicode::CaseFold.3.gz

PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Unicode/CaseFold
PLIST_DIRSTRY=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Unicode \
		%%SITE_PERL%%/%%PERL_ARCH%%/Unicode

post-install:
		${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Unicode/CaseFold/CaseFold.so

.include <bsd.port.mk>
