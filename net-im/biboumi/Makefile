PORTNAME=	biboumi
DISTVERSION=	9.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	https://git.louiz.org/biboumi/snapshot/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	samir@noir.im
COMMENT=	XMPP gateway to IRC

LICENSE=	ZLIB

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		cmake iconv localbase:ldflags pkgconfig python:build tar:xz

USE_GITHUB=	nodefault
GH_TUPLE=	catchorg:Catch2:v2.2.1:catch/external/src/catch

CMAKE_ARGS=	-DWITHOUT_SYSTEMD=1

OPTIONS_DEFINE=		DOCS LIBIDN PGSQL SQLITE3 TLS UDNS
OPTIONS_DEFAULT=	LIBIDN PGSQL SQLITE3 TLS UDNS

LIBIDN_DESC=		Stringprep functionality, to provide JIDs for IRC users
PGSQL_DESC=		Store users' options and messages in PostgreSQL
SQLITE3_DESC=		Store users' options and messages in SQLite
TLS_DESC=		Support TLS connections to IRC servers
UDNS_DESC=		Asynchronously resolve domain names, for better performances

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme
DOCS_PORTDOCS=		*

LIBIDN_LIB_DEPENDS=	libidn.so:dns/libidn
LIBIDN_CMAKE_ON=	-DWITH_LIBIDN=1
LIBIDN_CMAKE_OFF=	-DWITHOUT_LIBIDN=1

PGSQL_USES=		pgsql
PGSQL_CMAKE_ON=		-DWITH_POSTGRESQL=1
PGSQL_CMAKE_OFF=	-DWITHOUT_POSTGRESQL=1

SQLITE3_USES=		sqlite:3
SQLITE3_CMAKE_ON=	-DWITH_SQLITE3=1
SQLITE3_CMAKE_OFF=	-DWITHOUT_SQLITE3=1

TLS_LIB_DEPENDS=	libbotan-2.so:security/botan2
TLS_LIB_DEPENDS_OFF=	libgcrypt.so:security/libgcrypt
TLS_RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss
TLS_CMAKE_ON=		-DWITH_BOTAN=1
TLS_CMAKE_OFF=		-DWITHOUT_BOTAN=1

UDNS_LIB_DEPENDS=	libudns.so:dns/udns
UDNS_CMAKE_ON=		-DWITH_UDNS=1
UDNS_CMAKE_OFF=		-DWITHOUT_UDNS=1

USERS=		biboumi
GROUPS=		${USERS}

USE_RC_SUBR=	biboumi
SUB_LIST=	USER=${USERS} GROUP=${GROUPS}
PLIST_SUB=	${SUB_LIST}
SUB_FILES=	pkg-message

post-patch:
	${REINPLACE_CMD} -e 's,GIT_REPOSITORY.*Catch.git",SOURCE_DIR "${WRKSRC}/external/src/catch",' ${WRKSRC}/CMakeLists.txt

post-build:
	cd ${WRKSRC}/doc && ${MAKE} man

post-build-DOCS-on:
	cd ${WRKSRC}/doc && ${MAKE} html

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/biboumi ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/biboumi
	${INSTALL_DATA} ${WRKSRC}/conf/biboumi.cfg ${STAGEDIR}${ETCDIR}/biboumi.cfg.sample

post-install:
	${MKDIR} ${STAGEDIR}/var/db/biboumi
	${MKDIR} ${STAGEDIR}/var/run/biboumi
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/*policy.txt ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/_build/man/*.1 ${STAGEDIR}${PREFIX}/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/_build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo")

.include <bsd.port.mk>
