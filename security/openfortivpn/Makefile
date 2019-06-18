# $FreeBSD$

PORTNAME=	openfortivpn
PORTVERSION=	1.10.0
DISTVERSIONPREFIX=v
CATEGORIES=	security

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Client for PPP+SSL VPN tunnel services

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	adrienverge

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENSSL_LIBS="-lssl -lcrypto" OPENSSL_CFLAGS=${OPENSSLINC}

.include <bsd.port.mk>
