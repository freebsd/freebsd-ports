# Created by: Ache
# $FreeBSD$

PORTNAME=	Text-CSV_XS
PORTVERSION=	1.18
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HMBRAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Comma-separated values manipulation routines

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage \

USES=		perl5 tar:tgz
USE_PERL5=	configure

#pre-install:	test

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Text/CSV_XS/CSV_XS.so

.include <bsd.port.mk>
