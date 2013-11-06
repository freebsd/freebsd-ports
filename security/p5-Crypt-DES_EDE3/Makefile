# Created by: jesper
# $FreeBSD$

PORTNAME=	Crypt-DES_EDE3
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to a implementing 3-DES EDE encryption and decryption

BUILD_DEPENDS=	p5-Crypt-DES>=0:${PORTSDIR}/security/p5-Crypt-DES
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
