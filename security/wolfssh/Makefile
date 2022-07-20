PORTNAME=	wolfssh
PORTVERSION=	1.4.10
CATEGORIES=	security
MASTER_SITES=	https://www.wolfssl.com/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight SSH Library

LICENSE=	GPLv3

LIB_DEPENDS=	libwolfssl.so:security/wolfssl

USES=		autoreconf libtool localbase

CONFIGURE_ARGS=	--enable-fwd \
		--enable-keygen \
		--enable-scp \
		--enable-sftp \
		--enable-shared=yes \
		--enable-shell \
		--enable-static=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
