# $FreeBSD$

PORTNAME=	libstrophe
PORTVERSION=	0.9.2
CATEGORIES=	net-im

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Lightweight XMPP library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		libtool pkgconfig autoreconf ssl
USE_GITHUB=	yes
GH_ACCOUNT=	strophe
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=install-strip

.include <bsd.port.mk>
