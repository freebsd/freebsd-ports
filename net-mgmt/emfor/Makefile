PORTNAME=	emfor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	net-mgmt

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Health-check daemon that publishes healthy backends in a local store
WWW=		https://embark.systems/emfor \
		https://github.com/embark-systems/emfor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	embark-systems

# The repository root is a workspace: build and install only the daemon and
# emfor-check. EMFOR_PREFIX makes ${PREFIX}/etc/emfor/emfor.toml the
# default config path of emfor server, emfor check-config and emfor status
CARGO_BUILD_ARGS=	--package emfor-daemon --package emfor-check
CARGO_INSTALL_PATH=	crates/emfor-daemon crates/emfor-check
CARGO_ENV+=	EMFOR_PREFIX=${PREFIX}

# Add both to ports/UIDs and ports/GIDs (or pick free ids) before building.
USERS=		emfor
GROUPS=		emfor

USE_RC_SUBR=	emfor

EMFOR_ETCDIR?=	${PREFIX}/etc/emfor
EMFOR_DBDIR?=   /var/db/emfor

post-install:
	${MKDIR} ${STAGEDIR}${EMFOR_DBDIR} ${STAGEDIR}${EMFOR_ETCDIR}
	${SED} -e 's|/var/lib/emfor/|/var/db/emfor/|' \
		${WRKSRC}/examples/emfor.toml > ${WRKDIR}/emfor.toml.sample
	${INSTALL_DATA} ${WRKDIR}/emfor.toml.sample \
		${STAGEDIR}${PREFIX}/etc/emfor/emfor.toml.sample

.include <bsd.port.mk>
