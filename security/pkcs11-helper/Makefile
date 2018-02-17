# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkcs11-helper
PORTVERSION=	1.11
PORTREVISION=	3
CATEGORIES=	security devel
MASTER_SITES=	SF/opensc/pkcs11-helper/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Helper library for multiple PKCS\#11 providers

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/COPYING.BSD
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING.GPL

BROKEN_SSL=	openssl-devel

GNU_CONFIGURE=	yes
USES=		libtool:keepla pathfix pkgconfig tar:bzip2 ssl
USE_LDCONFIG=	yes

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

CONFIGURE_ARGS=	--disable-crypto-engine-gnutls \
		--disable-crypto-engine-nss

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|install-data-am: install-apidocDATA|install-data-am:|' \
		${WRKSRC}/doc/api/Makefile.in

.include <bsd.port.mk>
