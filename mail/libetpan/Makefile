# Created by: ijliao
# $FreeBSD$

PORTNAME=	libetpan
PORTVERSION=	1.9.4
CATEGORIES=	mail

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mail framework for C language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libsasl2.so:security/cyrus-sasl2

USES=		autoreconf compiler:c++11-lang gmake iconv libtool localbase pkgconfig

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS

USE_GITHUB=	yes
GH_ACCOUNT=	dinhviethoa

OPTIONS_DEFINE=		DOCS IPV6
OPTIONS_SINGLE=		CRYPTO
OPTIONS_SINGLE_CRYPTO=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL

GNUTLS_CONFIGURE_ON=	--without-openssl --with-gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error
IPV6_CONFIGURE_ENABLE=	ipv6
OPENSSL_CONFIGURE_WITH=	openssl="${OPENSSLBASE}"
OPENSSL_USES=		ssl

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
