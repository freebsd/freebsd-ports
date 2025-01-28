PORTNAME=	Search-VectorSpace
PORTVERSION=	0.02
PORTREVISION=	15
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Very basic vector-space search engine perl module
WWW=		https://metacpan.org/release/Search-VectorSpace

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Lingua-Stem>=0:textproc/p5-Lingua-Stem \
		p5-PDL>=0:math/p5-PDL

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
