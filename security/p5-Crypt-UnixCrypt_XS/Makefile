# Created by: brix@FreeBSD.org
# $FreeBSD$

PORTNAME=	Crypt-UnixCrypt_XS
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl XS interface for a portable traditional crypt function

LICENSE=	ARTPERL10

USES=		perl5
USE_PERL5=	configure
MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/UnixCrypt_XS/UnixCrypt_XS.so

.include <bsd.port.mk>
