# Created by: Sander Vesik <sander@haldjas.folklore.ee>
# $FreeBSD$

PORTNAME=	Math-MatrixReal
PORTVERSION=	2.13
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module implementing a Matrix of Reals

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

# Hopefully this is only needed for v2.13.
post-patch:
	@${FIND} ${WRKSRC} -name '*.pm.swo' -delete

.include <bsd.port.mk>
