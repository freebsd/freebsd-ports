# Created by: perl@FreeBSD.org
# $FreeBSD$

PORTNAME=	Crypt-RHash
PORTVERSION=	0.91
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compute hash sums and magnet links

LICENSE=	MIT

USES=		perl5
USE_PERL5=	configure fixpacklist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Crypt/Rhash/Rhash.so

.include <bsd.port.mk>
