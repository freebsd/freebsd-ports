# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PDF-API2-XS
PORTVERSION=	1.001
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Optional PDF::API2 add-on using XS to speed up expensive operations

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-PDF-API2>=0:textproc/p5-PDF-API2

USES=		gmake perl5
USE_CSTD=	c99
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/PDF/API2/XS/ImagePNG/ImagePNG.so

.include <bsd.port.mk>
