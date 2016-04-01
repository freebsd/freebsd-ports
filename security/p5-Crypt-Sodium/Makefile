# Created by: Thomas von Dein <freebsd@daemon.de>
# $FreeBSD$

PORTNAME=	Crypt-Sodium
PORTVERSION=	0.07
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd@daemon.de
COMMENT=	Perl bindings for portable NaCL (libsodium)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	libsodium.so:security/libsodium

CFLAGS+=	-I${LOCALBASE}/include
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
