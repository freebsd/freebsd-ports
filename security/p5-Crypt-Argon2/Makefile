# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	Crypt-Argon2
PORTVERSION=	0.008
CATEGORIES=	security
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl interface to the Argon2 key derivation functions

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/README

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/Argon2/Argon2.so

.include <bsd.port.mk>
