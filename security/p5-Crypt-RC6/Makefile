# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	Crypt-RC6
PORTVERSION=	1.0
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl implementation of the RC6 encryption algorithm

USES=		perl5
USE_PERL5=	configure

do-patch:
	${REINPLACE_CMD} -e 's///' ${WRKSRC}/RC6.pm

.include <bsd.port.mk>
