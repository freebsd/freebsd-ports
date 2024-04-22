PORTNAME=	postsrsd
DISTVERSION=	2.0.9
PORTEPOCH=	1
CATEGORIES=	mail

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Postfix Sender Rewriting Scheme daemon
WWW=		https://github.com/roehling/postsrsd

LICENSE=	BSD3CLAUSE GPLv3+
LICENSE_COMB=	dual

LIB_DEPENDS=	libconfuse.so:devel/libconfuse

USES=		cmake cpe pkgconfig

CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	roehling
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}

CMAKE_ARGS=	--no-warn-unused-cli \
		-DBUILD_TESTING=OFF \
		-DCMAKE_BUILD_TYPE=Release \
		-DFETCHCONTENT_TRY_FIND_PACKAGE_MODE=ALWAYS \
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DCMAKE_LIBRARY_PATH="${LOCALBASE}/lib"

SUB_FILES=	pkg-message

PLIST_FILES=	\
		sbin/postsrsd \
		"@sample ${ETCDIR}.conf.sample" \
		"@dir /var/db/${PORTNAME}" \
		"@dir /var/run/${PORTNAME}"

PORTDOCS=	CHANGELOG.rst README.rst postsrsd.conf

OPTIONS_DEFINE=	DOCS REDIS SQLITE

DOCS_CMAKE_BOOL=	ENABLE_DOCS

REDIS_DESC=		Store envelope senders in redis
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
REDIS_CMAKE_BOOL=	WITH_REDIS

SQLITE_DESC=	Use sqlite3 backebd for storing envelope senders
SQLITE_USES=	sqlite
SQLITE_CMAKE_BOOL=	WITH_SQLITE

post-patch:
		${REINPLACE_CMD} -e '/^chroot-dir/ s/^/#/' ${WRKSRC}/doc/postsrsd.conf

post-install:
		${INSTALL_DATA} ${WRKSRC}/doc/postsrsd.conf ${STAGEDIR}${PREFIX}/etc/postsrsd.conf.sample
		${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}

.include <bsd.port.mk>
