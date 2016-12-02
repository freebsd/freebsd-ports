# Created by: brix@FreeBSD.org
# $FreeBSD$

PORTNAME=	Crypt-UnixCrypt_XS
PORTVERSION=	0.11
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl XS interface for a portable traditional crypt function

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/UnixCrypt_XS/UnixCrypt_XS.so

.include <bsd.port.mk>
