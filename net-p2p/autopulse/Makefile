PORTNAME=	autopulse
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	net-p2p

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Scan MultiMedia library on webhook triggers
WWW=		https://github.com/dan-online/autopulse

LICENSE=	MIT

LIB_DEPENDS+=	libzstd.so:archivers/zstd

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	dan-online
USE_RC_SUBR=	autopulse

CARGO_FEATURES=	--no-default-features

SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		autopulse
GROUPS=		autopulse

PLIST_FILES=	bin/autopulse \
		"@sample etc/autopulse.yml.sample"

OPTIONS_DEFINE=	SQLITE POSTGRES
OPTIONS_DEFAULT=	SQLITE

POSTGRES_DESC=	postgresql database support
POSTGRES_USES=	pgsql
POSTGRES_VARS=	WANT_PGSQL=client CARGO_FEATURES+=postgres

SQLITE_DESC=	sqlite3 database support
SQLITE_USES=	sqlite:3
SQLITE_VARS=	CARGO_FEATURES+=sqlite

post-stage:
	${INSTALL_DATA} ${FILESDIR}/autopulse.yml.sample \
		${STAGEDIR}${PREFIX}/etc/autopulse.yml.sample

.include <bsd.port.mk>
