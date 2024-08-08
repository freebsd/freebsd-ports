PORTNAME=	wolfssh
PORTVERSION=	1.4.18
CATEGORIES=	security
MASTER_SITES=	https://www.wolfssl.com/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight SSH Library
WWW=		https://www.wolfssl.com/products/wolfssh/ \
		https://github.com/wolfSSL/wolfssh

LICENSE=	GPLv3

LIB_DEPENDS=	libwolfssl.so:security/wolfssl
TEST_DEPENDS=	bash:shells/bash

USES=		libtool localbase shebangfix

CONFIGURE_ARGS=	--disable-smallstack \
		--enable-agent \
		--enable-certs \
		--enable-examples \
		--enable-fwd \
		--enable-keygen \
		--enable-scp \
		--enable-sftp \
		--enable-shared=yes \
		--enable-shell \
		--enable-static=yes \
		--enable-term
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

SHEBANG_FILES=	scripts/get-put.test

.include <bsd.port.mk>
