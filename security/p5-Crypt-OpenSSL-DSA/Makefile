# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	Crypt-OpenSSL-DSA
PORTVERSION=	0.14
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to DSA signature verification using OpenSSL

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/lib/Crypt/OpenSSL/DSA.pm.orig

.include <bsd.port.mk>
