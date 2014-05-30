# Created by: ijliao
# $FreeBSD$

PORTNAME=	libetpan
PORTVERSION=	1.5
CATEGORIES=	mail ipv6

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Mail framework for C language

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

USE_GITHUB=	yes
GH_ACCOUNT=	dinhviethoa
GH_COMMIT=	34bab37

USE_AUTOTOOLS=	aclocal autoconf autoheader automake libtoolize
AUTOMAKE_ARGS=	--add-missing --foreign --force --copy
USES=		gmake iconv libtool
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

OPTIONS_DEFINE=		IPV6
OPTIONS_SINGLE=		CRYPTO
OPTIONS_SINGLE_CRYPTO=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL

GNUTLS_CONFIGURE_ON=	--without-openssl --with-gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
			libgcrypt.so:${PORTSDIR}/security/libgcrypt

IPV6_CONFIGURE_ENABLE=	ipv6

OPENSSL_CONFIGURE_ON=	--with-openssl="${OPENSSLBASE}"
OPENSSL_USE=		OPENSSL=yes

.include <bsd.port.mk>
