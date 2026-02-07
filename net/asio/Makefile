PORTNAME=	asio
DISTVERSION=	1.34.2
CATEGORIES=	net devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}%20(Stable)/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Cross-platform C++ library for network and low-level I/O programming
WWW=		https://think-async.com/Asio/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

USES=		tar:bz2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-noarch-pkgconfigdir=${PREFIX}/libdata/pkgconfig

NO_BUILD=	yes
NO_ARCH=	yes

INSTALL_TARGET=	install-data

.include <bsd.port.mk>
