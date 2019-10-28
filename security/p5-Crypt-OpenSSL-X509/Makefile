# Created by: kftseng@iyard.org
# $FreeBSD$

PORTNAME=	Crypt-OpenSSL-X509
PORTVERSION=	1.813
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for OpenSSL X509 API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 ssl
USE_PERL5=	configure

MAKE_ARGS=	PASTHRU_INC=-I${OPENSSLINC}

post-patch:
	@${REINPLACE_CMD} -e '/cc_optimize_flags/ s| -Werror||' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_ARCH}/auto/Crypt/OpenSSL/X509/X509.so

.include <bsd.port.mk>
