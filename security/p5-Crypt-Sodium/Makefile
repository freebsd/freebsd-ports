# Created by: Thomas von Dein <freebsd@daemon.de>
# $FreeBSD$

PORTNAME=	Crypt-Sodium
PORTVERSION=	0.06
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd@daemon.de
COMMENT=	Perl bindings for portable NaCL (libsodium)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

LIB_DEPENDS+=	libsodium.so:${PORTSDIR}/security/libsodium
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
