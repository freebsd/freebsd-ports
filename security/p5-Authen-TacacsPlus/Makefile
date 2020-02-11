# Created by: will
# $FreeBSD$

PORTNAME=	Authen-TacacsPlus
PORTVERSION=	0.27
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that provides authentication using a tacacs+ server

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Authen/TacacsPlus/TacacsPlus.so

.include <bsd.port.mk>
