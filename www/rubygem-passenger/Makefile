# Created by: Jacob Atzen <jatzen@gmail.com>
# $FreeBSD$

PORTNAME=	passenger
PORTVERSION=	5.1.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Modules for running Ruby on Rails and Rack applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rake:devel/rubygem-rake

CPE_VENDOR=	phusion
CPE_PRODUCT=	passenger

OPTIONS_DEFINE=	DEBUG SYMLINK
OPTIONS_SINGLE=	SERVER
OPTIONS_SINGLE_SERVER=	APACHE22 NGINX
APACHE22_DESC=	Build with apache22 support
NGINX_DESC=	Build with nginx support
SYMLINK_DESC=	Create passenger symlink
OPTIONS_DEFAULT=	APACHE22

USE_RUBY=	yes
RAKE_BIN=	${LOCALBASE}/bin/rake
USES=		cpe gem
NOPORTDOCS=	yes

APACHE22_USE=	APACHE=22+

LIB_DEPENDS+=	libuv.so:devel/libuv \
		libcurl.so:ftp/curl
BUILD_DEPENDS+=	rubygem-rack16>=0:www/rubygem-rack16
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_LIST+=	GEM_LIB_DIR=${GEM_LIB_DIR} RUBY=${RUBY}
SUB_FILES=	pkg-message

PLIST_FILES=	bin/passenger \
		bin/passenger-config \
		bin/passenger-install-apache2-module \
		bin/passenger-memory-stats \
		bin/passenger-status \
		bin/passenger-install-nginx-module

SYMLINK_PLIST_FILES=	${GEMS_DIR}/${PORTNAME}
SYMLINK_SUB_LIST=	PASSENGER_INSTALL_DIR="${PREFIX}/${GEMS_DIR}/${PORTNAME}"
SYMLINK_SUB_LIST_OFF=	PASSENGER_INSTALL_DIR="${PREFIX}/${GEM_LIB_DIR}"

pre-patch:
	@${REINPLACE_CMD} \
		's!-Wall!!g; \
		s!gcc!${CC}!g; \
		s!g++!${CXX}!g; \
		s!#{PlatformInfo.debugging_cflags}!${CFLAGS}!g; \
		s!-O2!!g; \
		s! -feliminate-unused-debug-symbols -feliminate-unused-debug-types!!g; \
		166s!true!false!' \
		${WRKSRC}/build/basics.rb

pre-patch-DEBUG-off:
	@${REINPLACE_CMD} \
		's!-DPASSENGER_DEBUG!-DNDEBUG!g' \
		${WRKSRC}/build/basics.rb

pre-patch-NGINX-on:
	@${ECHO_CMD}
	@${ECHO_CMD} "Do not forget compile www/nginx"
	@${ECHO_CMD} "with PASSENGER_MODULE support"
	@${ECHO_CMD}

post-build:
	${FIND} ${WRKSRC} -name '*.o' -delete
	${FIND} ${WRKSRC} -name '*.bak' -delete

post-build-APACHE22-on:
	(CC=${CC} CXX=${CXX} ${WRKSRC}/bin/passenger-install-apache2-module --auto)

post-build-NGINX-on:
	(cd ${WRKSRC} && CC=${CC} CXX=${CXX} ${RAKE_BIN} nginx)

post-install:
	( cd ${WRKSRC} && \
	${COPYTREE_SHARE} buildout ${STAGEDIR}${PREFIX}/${GEMS_DIR}/${PORTNAME}-${PORTVERSION} )
	${CHMOD} +x ${STAGEDIR}${PREFIX}/${GEMS_DIR}/${PORTNAME}-${PORTVERSION}/buildout/support-binaries/*

post-install-SYMLINK-on:
	${LN} -s ${GEM_NAME} ${STAGEDIR}${PREFIX}/${GEMS_DIR}/${PORTNAME}

.include <bsd.port.mk>
