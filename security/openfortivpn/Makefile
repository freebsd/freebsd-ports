# $FreeBSD$

PORTNAME=	openfortivpn
PORTVERSION=	1.14.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security net-vpn

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Client for PPP+SSL VPN tunnel services

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	adrienverge

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENSSL_CFLAGS=${OPENSSLINC} \
		OPENSSL_LIBS="-lssl -lcrypto"

.include <bsd.port.mk>
