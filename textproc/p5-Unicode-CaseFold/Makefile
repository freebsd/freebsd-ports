# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Unicode-CaseFold
PORTVERSION=	1.01
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

PLIST_FILES=	%%SITE_ARCH%%/Unicode/CaseFold.pm \
		%%SITE_ARCH%%/Unicode/CaseFoldPP.pm \
		%%SITE_ARCH%%/auto/Unicode/CaseFold/CaseFold.so \
		%%PERL5_MAN3%%/Unicode::CaseFold.3.gz

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Unicode/CaseFold/CaseFold.so

.include <bsd.port.mk>
