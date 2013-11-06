# Created by: will
# $FreeBSD$

PORTNAME=	Authen-TacacsPlus
PORTVERSION=	0.24
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIKEM/Authen-TacacsPlus
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that provides authentication using a tacacs+ server

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure
MAKE_ENV+=	CCFLAGS="${CFLAGS}"

pre-build:
	${PERL} -pi -e "s:CCFLAGS =:CCFLAGS ?=:g" ${WRKSRC}/tacpluslib/Makefile

.include <bsd.port.mk>
