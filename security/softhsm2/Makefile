PORTNAME=	softhsm
PORTVERSION=	2.6.1
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://dist.opendnssec.org/source/ \
		http://dist.opendnssec.org/source/testing/
PKGNAMESUFFIX=	2

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Software implementation of a Hardware Security Module (HSM)
WWW=		https://www.opendnssec.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS+=		p11-kit:security/p11-kit
BUILD_DEPENDS+=		${MY_DEPENDS}
RUN_DEPENDS+=		${MY_DEPENDS}

USES=		compiler:c++11-lang libtool pkgconfig ssl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CONFIGURE_ARGS+=	--with-crypto-backend=openssl \
			--with-openssl=${OPENSSLBASE} \
			--disable-gost

INSTALL_TARGET=	install-strip

CONFLICTS=	softhsm-1.*

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		SQLITE MIGRATE
OPTIONS_DEFAULT=	CRYP_OPEN SQLITE MIGRATE

OPTIONS_SUB=		yes
MIGRATE_DESC=		Build the migration tool
SQLITE_DESC=		Build with object store backend DB support (SQLITE3)

MIGRATE_IMPLIES=	SQLITE
MIGRATE_CONFIGURE_WITH=	migrate

SQLITE_USES=		sqlite
SQLITE_CONFIGURE_WITH=	sqlite3=${LOCALBASE} objectstore-backend-db

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/p11-kit/modules
	${INSTALL_DATA} ${WRKSRC}/softhsm2.module \
		${STAGEDIR}${PREFIX}/share/p11-kit/modules

.include <bsd.port.mk>
