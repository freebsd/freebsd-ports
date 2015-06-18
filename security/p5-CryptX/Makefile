# Created by: vanilla@
# $FreeBSD$

PORTNAME=	CryptX
PORTVERSION=	0.023
CATEGORIES=	security perl5
MASTER_SITES=	CPAN/Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Crypto toolkit

USES=		perl5
USE_PERL5=	modbuild

regression-test: build
	@cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${PERL5} ${PL_BUILD} ${MAKE_ARGS} test

.include <bsd.port.mk>
