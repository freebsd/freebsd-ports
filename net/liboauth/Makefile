# $FreeBSD$

PORTNAME=	liboauth
PORTVERSION=	1.0.3
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	C library implementing the OAuth Core standard

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.MIT

BROKEN_SSL=	openssl-devel
BROKEN_SSL_REASON_openssl-devel=	error: variable has incomplete type 'EVP_MD_CTX' (aka 'struct evp_md_ctx_st')

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		libtool pkgconfig ssl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e '/PC_REQ=/s/ libcrypto//' ${WRKSRC}/configure

.include <bsd.port.mk>
