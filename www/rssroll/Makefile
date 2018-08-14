# $FreeBSD$

PORTNAME=	rssroll
PORTVERSION=	0.6
CATEGORIES=	www

MAINTAINER=	koue@chaosophia.net
COMMENT=	RSS collector in C

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libxml2.so:textproc/libxml2 \
		libsqlite3.so:databases/sqlite3

USES=		cmake

CEZ_VERSION=	1.01
USE_GITHUB=	yes
GH_ACCOUNT=	koue

GH_PROJECT=	rssroll:rssroll \
		libcez:libcez
GH_TAGNAME=	${CEZ_VERSION}:libcez

pre-configure:
	@(cd ${WRKDIR}/libcez-${CEZ_VERSION} && ${SETENV} ${MAKE_ENV} ${MAKE})
	${REINPLACE_CMD} -e 's|cez_config.h|cez_config.h PATHS ${WRKDIR}/libcez-${CEZ_VERSION}/src/config NO_DEFAULT_PATH|g' \
			 -e 's|cez_fossil.h|cez_fossil.h PATHS ${WRKDIR}/libcez-${CEZ_VERSION}/src/fossil NO_DEFAULT_PATH|g' \
			 -e 's|cez_misc.h|cez_misc.h PATHS ${WRKDIR}/libcez-${CEZ_VERSION}/src/misc NO_DEFAULT_PATH|g' \
			 -e 's|cezconfig|cezconfig PATHS ${WRKDIR}/libcez-${CEZ_VERSION}/src/config NO_DEFAULT_PATH|g' \
			 -e 's|cezfossil|cezfossil PATHS ${WRKDIR}/libcez-${CEZ_VERSION}/src/fossil NO_DEFAULT_PATH|g' \
			 -e 's|cezmisc|cezmisc PATHS ${WRKDIR}/libcez-${CEZ_VERSION}/src/misc NO_DEFAULT_PATH|g' \
		${WRKSRC}/cmake/FindLibcez.cmake

.include <bsd.port.mk>
