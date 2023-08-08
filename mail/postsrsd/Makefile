PORTNAME=	postsrsd
DISTVERSION=	2.0.6
CATEGORIES=	mail

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Postfix Sender Rewriting Scheme daemon
WWW=		https://github.com/roehling/postsrsd

LICENSE=	BSD3CLAUSE GPLv3+
LICENSE_COMB=	dual

LIB_DEPENDS=	libconfuse.so:devel/libconfuse

USES=		cmake cpe pkgconfig
USE_LDCONFIG=	yes

CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	roehling
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	DOCS REDIS

DOCS_CMAKE_BOOL=	ENABLE_DOCS

REDIS_DESC=		Store envelope senders in redis
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
REDIS_CMAKE_BOOL=	WITH_REDIS

CMAKE_ARGS=	--no-warn-unused-cli \
		-DBUILD_TESTING=OFF \
		-DCMAKE_BUILD_TYPE=Release \
		-DFETCHCONTENT_TRY_FIND_PACKAGE_MODE=ALWAYS \
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DCMAKE_LIBRARY_PATH="${LOCALBASE}/lib"

PLIST_FILES=	\
		sbin/postsrsd \
		${LOCALBASE}/etc/${PORTNAME}.secret

PORTDOCS=	README.rst CHANGELOG.rst postsrsd.conf

.include <bsd.port.mk>
