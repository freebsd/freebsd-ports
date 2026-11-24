PORTNAME=	autopulse
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	net-p2p

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Scan MultiMedia library on webhook triggers
WWW=		https://github.com/dan-online/autopulse

LICENSE=	MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	dan-online
USE_RC_SUBR=	autopulse

CARGO_FEATURES=	--no-default-features

SUB_LIST=	GROUPS=${GROUPS} \
		USERS=${USERS}

USERS=		autopulse
GROUPS=		autopulse

OPTIONS_DEFINE=		POSTGRES SQLITE
OPTIONS_DEFAULT=	SQLITE

POSTGRES_DESC=	postgresql database support
SQLITE_DESC=	sqlite3 database support

POSTGRES_USES=	pgsql
POSTGRES_VARS=	CARGO_FEATURES+=postgres \
		WANT_PGSQL=client
SQLITE_USES=	sqlite:3
SQLITE_VARS=	CARGO_FEATURES+=sqlite

post-stage:
	${INSTALL_DATA} ${FILESDIR}/autopulse.yml.sample \
		${STAGEDIR}${PREFIX}/etc/autopulse.yml.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/autopulse.newsyslog \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/autopulse.conf.sample

.include <bsd.port.mk>
