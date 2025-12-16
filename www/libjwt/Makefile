PORTNAME=	libjwt
PORTVERSION=	2.1.2
CATEGORIES=	www
MASTER_SITES=	https://github.com/benmcollins/libjwt/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON Web Token implementation in C
WWW=		https://libjwt.io/ \
		https://github.com/benmcollins/libjwt

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	jansson>=2.0:devel/jansson
LIB_DEPENDS=	libjansson.so:devel/jansson
TEST_DEPENDS=	check>=0.9.4:devel/check

USES=		gmake libtool pkgconfig ssl tar:bz2

CONFIGURE_ARGS=	--disable-doxygen-chi \
		--disable-doxygen-chm \
		--disable-doxygen-doc \
		--disable-doxygen-dot \
		--disable-doxygen-html \
		--disable-doxygen-man \
		--disable-doxygen-pdf \
		--disable-doxygen-ps \
		--disable-doxygen-rtf \
		--disable-doxygen-xml
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_ARGS=	CFLAGS+=-I${LOCALBASE}/include LIBS+="-L${LOCALBASE}/lib -lcheck"
TEST_TARGET=	check
USE_LDCONFIG=	yes

PORTSCOUT=	limit:^2\.

OPTIONS_DEFINE=	GNUTLS

GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

.include <bsd.port.mk>
