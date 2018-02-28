# Created by: Jaap Akkerhuis <jaap@NLnetLabs.nl>
# $FreeBSD$

PORTNAME=	softhsm
PORTVERSION=	2.4.0
CATEGORIES=	security
MASTER_SITES=	http://dist.opendnssec.org/source/ \
		http://dist.opendnssec.org/source/testing/
PKGNAMESUFFIX=	2

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Software implementation of a Hardware Security Module (HSM)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool ssl pkgconfig

SUB_FILES=	pkg-message

CONFLICTS=	softhsm-1.*

USE_LDCONFIG=	yes

LIB_DEPENDS+=		libcppunit.so:devel/cppunit

OPTIONS_DEFINE=		SQLITE
OPTIONS_SUB=		yes
SQLITE_DESC=		Build with object store backend DB support (SQLITE3)

OPTIONS_SINGLE=		CRYP
OPTIONS_SINGLE_CRYP=	CRYP_OPEN CRYP_BOTAN

CRYP_OPEN_DESC=		Build with OpenSSL crypto library
CRYP_BOTAN_DESC=	Build with Botan crypto library

OPTIONS_DEFAULT=	CRYP_OPEN

SQLITE_CONFIGURE_WITH=	sqlite3=${LOCALBASE} objectstore-backend-db
SQLITE_USES=		sqlite

CRYP_BOTAN_CONFIGURE_ON=	--with-crypto-backend=botan
CRYP_BOTAN_LIB_DEPENDS=	libbotan-1.10.so:security/botan110

CRYP_OPEN_CONFIGURE_ON=	--with-crypto-backend=openssl

.include <bsd.port.options.mk>

.if ${SSL_DEFAULT:Mlibressl*} || ${SSL_DEFAULT:Mopenssl-devel}
CONFIGURE_ARGS+=	--disable-gost
.endif

.if ${SSL_DEFAULT:Mopenssl-devel}
CONFIGURE_ARGS+=	--disable-gost
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/p11-kit/modules
	${INSTALL_DATA} ${WRKSRC}/softhsm2.module \
		${STAGEDIR}${PREFIX}/share/p11-kit/modules

.include <bsd.port.mk>
