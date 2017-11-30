# Created by: Jacob Atzen <jatzen@gmail.com>
# $FreeBSD$

PORTNAME=	passenger
PORTVERSION=	5.1.12
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
USES=		cpe gem libtool shebangfix ssl
SHEBANG_FILES=	\
	src/cxx_supportlib/vendor-copy/libuv/gyp_uv.py \
	dev/vagrant/nginx_start \
	dev/vagrant/provision.sh \
	dev/ci/run-tests-with-docker \
	dev/ci/scripts/setup-host-natively.sh \
	dev/ci/scripts/docker-entrypoint-stage2.sh \
	dev/ci/scripts/inituidgid \
	dev/ci/scripts/debug-console-wrapper.sh \
	dev/ci/scripts/run-tests-natively-stage2.sh \
	dev/ci/scripts/docker-entrypoint.sh \
	dev/ci/run-tests-natively \
	dev/ci/setup-host

NOPORTDOCS=	yes

APACHE22_USE=	APACHE=22+

LIB_DEPENDS+=	libuv.so:devel/libuv \
		libcurl.so:ftp/curl \
		libunwind.so:devel/libunwind \
		libapr-1.so:devel/apr1

BUILD_DEPENDS+=	rubygem-rack16>=0:www/rubygem-rack16
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_LIST+=	GEM_LIB_DIR=${GEM_LIB_DIR} RUBY=${RUBY}
SUB_FILES=	pkg-message

PLIST_DIRS=	${GEM_LIB_DIR}/buildout/common/libboost_oxt/boost \
	${GEM_LIB_DIR}/buildout/common/libboost_oxt/oxt \
	${GEM_LIB_DIR}/buildout/common/libpassenger_common/DataStructures \
	${GEM_LIB_DIR}/buildout/common/libpassenger_common/MemoryKit \
	${GEM_LIB_DIR}/buildout/common/libpassenger_common/ServerKit \
	${GEM_LIB_DIR}/buildout/common/libpassenger_common/Utils \
	${GEM_LIB_DIR}/buildout/common/libpassenger_common/vendor-modified \
	${GEM_LIB_DIR}/download_cache

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
		155s!true!false!' \
		${WRKSRC}/build/basics.rb
	@${REINPLACE_CMD} '1s:python:python2:' \
		${WRKSRC}/src/cxx_supportlib/vendor-copy/libuv/gyp_uv.py

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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/buildout/ruby/*/passenger_native_support.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/buildout/support-binaries/PassengerAgent

post-install-APACHE22-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/buildout/apache2/mod_passenger.so

post-install-SYMLINK-on:
	${LN} -s ${GEM_NAME} ${STAGEDIR}${PREFIX}/${GEMS_DIR}/${PORTNAME}

.include <bsd.port.mk>
