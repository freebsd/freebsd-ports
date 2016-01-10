# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	softhsm
PORTVERSION=	2.0.0
CATEGORIES=	security
MASTER_SITES=	http://dist.opendnssec.org/source/ \
		http://dist.opendnssec.org/source/testing/
PKGNAMESUFFIX=	2

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Software implementation of a Hardware Security Module (HSM)

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

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

CRYP_BOTAN_CONFIGURE_WITH=	crypto-backend=botan

.if defined(OPENSSL_PORT) && ${OPENSSL_PORT} == security/libressl
CONFIGURE_ARGS+=	--disable-gost
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCRYP_BOTAN}
LIB_DEPENDS+=	libbotan-1.10.so:${PORTSDIR}/security/botan110
.endif

.if ${PORT_OPTIONS:MCRYP_OPEN}
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes
CONFIGURE_ARGS+=	--with-crypto-backend=openssl
.endif

.include <bsd.port.mk>
