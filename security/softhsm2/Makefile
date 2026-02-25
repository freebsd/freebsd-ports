PORTNAME=	softhsm
DISTVERSION=	2.7.0
CATEGORIES=	security
PKGNAMESUFFIX=	2

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Software implementation of a Hardware Security Module (HSM)
WWW=		https://www.softhsm.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	p11-kit:security/p11-kit
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		autoreconf compiler:c++11-lang libtool pkgconfig ssl
USE_GITHUB=	yes
GH_PROJECT=	SoftHSMv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gost \
		--with-crypto-backend=openssl \
		--with-openssl=${OPENSSLBASE}

INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		SQLITE MIGRATE
OPTIONS_DEFAULT=	SQLITE MIGRATE

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
