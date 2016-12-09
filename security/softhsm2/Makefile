# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	softhsm
PORTVERSION=	2.2.0
CATEGORIES=	security
MASTER_SITES=	http://dist.opendnssec.org/source/ \
		http://dist.opendnssec.org/source/testing/
PKGNAMESUFFIX=	2

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Software implementation of a Hardware Security Module (HSM)

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sqlite3=${LOCALBASE} --localstatedir="${PREFIX}/var"
INSTALL_TARGET=	install-strip
USES=		libtool sqlite

CONFLICTS=	softhsm-1.*

USE_LDCONFIG=	yes

OPTIONS_SINGLE=		CRYP
OPTIONS_SINGLE_CRYP=	CRYP_OPEN CRYP_BOTAN

CRYP_OPEN_DESC=		Build with OpenSSL crypto library
CRYP_BOTAN_DESC=	Build with Botan crypto library

OPTIONS_DEFAULT=	CRYP_OPEN

CRYP_BOTAN_CONFIGURE_ON=	--with-crypto-backend=botan
CRYP_BOTAN_LIB_DEPENDS=	libbotan-1.10.so:security/botan110
CRYP_OPEN_USE=		openssl=yes
CRYP_OPEN_VARS=		WITH_OPENSSL_PORT=yes
CRYP_OPEN_CONFIGURE_ON=	--with-crypto-backend=openssl

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
CONFIGURE_ARGS+=	--disable-gost
.endif

.include <bsd.port.post.mk>
