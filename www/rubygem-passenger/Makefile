PORTNAME=	passenger
PORTVERSION=	6.0.27
CATEGORIES=	www rubygems
MASTER_SITES=	RG \
		https://github.com/phusion/passenger/releases/download/release-${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modules for running Ruby on Rails and Rack applications
WWW=		https://www.phusionpassenger.com/ \
		https://github.com/phusion/passenger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rubygem-rack>=1.6.13,3:www/rubygem-rack \
		rubygem-rake>=12.3.3:devel/rubygem-rake \
		utf8cpp>=4.0.3:devel/utf8cpp
LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libcurl.so:ftp/curl \
		libuv.so:devel/libuv
RUN_DEPENDS=	rubygem-etc>=0:devel/rubygem-etc \
		rubygem-rack>=1.6.13,3:www/rubygem-rack \
		rubygem-rackup>=1.0.1:www/rubygem-rackup \
		rubygem-rake>=12.3.3:devel/rubygem-rake

USES=		compiler:c++14-lang cpe gem libtool python:env ssl

CXXFLAGS+=	-I${LOCALBASE}/include/utf8cpp
USE_CXXSTD=	c++14

PLIST_FILES=	bin/passenger \
		bin/passenger-config \
		bin/passenger-memory-stats \
		bin/passenger-status

SUB_FILES=	pkg-message-${FLAVOR}
SUB_LIST=	GEM_LIB_DIR=${GEM_LIB_DIR} RUBY=${RUBY}

CONFLICTS_INSTALL=	rubygem-passenger-apache rubygem-passenger-nginx

CPE_VENDOR=	phusion

FLAVORS=	apache nginx
FLAVOR?=	${FLAVORS:[1]}
apache_PKGNAMESUFFIX=	-apache
nginx_PKGNAMESUFFIX=	-nginx

.if ${FLAVOR} == apache
USES+=		apache
.endif

OPTIONS_DEFINE=	DEBUG SYMLINK
OPTIONS_DEFAULT=SYMLINK
OPTIONS_EXCLUDE=DOCS
SYMLINK_DESC=	Create passenger symlink

SYMLINK_PLIST_FILES=	${GEMS_DIR}/passenger
SYMLINK_SUB_LIST=	PASSENGER_INSTALL_DIR="${PREFIX}/${GEMS_DIR}/passenger"
SYMLINK_SUB_LIST_OFF=	PASSENGER_INSTALL_DIR="${PREFIX}/${GEM_LIB_DIR}"

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/src/cxx_supportlib/vendor-copy/libuv/
	@${RM} -r ${WRKSRC}/src/cxx_supportlib/vendor-copy/utf8*

post-patch-DEBUG-off:
	@${REINPLACE_CMD} 's|-DPASSENGER_DEBUG|-DNDEBUG|g' ${WRKSRC}/build/basics.rb

post-build:
.if ${FLAVOR} == apache
	${SETENV} CC=${CC} CXX=${CXX} EXTRA_CXXFLAGS="${CXXFLAGS}" USE_VENDORED_LIBUV=false ${WRKSRC}/bin/passenger-install-apache2-module --auto
.endif
.if ${FLAVOR} == nginx
	cd ${WRKSRC} && ${SETENV} CC=${CC} CXX=${CXX} EXTRA_CXXFLAGS="${CXXFLAGS}" USE_VENDORED_LIBUV=false ${LOCALBASE}/bin/rake nginx
.endif
	${FIND} ${WRKSRC} -name '*.bak' -o -name '*.o' -o -name '*.orig' -delete

post-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} buildout ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/
	${CHMOD} +x ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/buildout/support-binaries/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/buildout/ruby/*/passenger_native_support.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/buildout/support-binaries/PassengerAgent
	${FIND} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR} -type d -empty -delete
.if ${FLAVOR} == apache
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/buildout/apache2/mod_passenger.so
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${LN} -sf ../../${GEM_LIB_DIR}/buildout/apache2/mod_passenger.so ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_passenger.so
	@${ECHO_CMD} "${APACHEMODDIR}/mod_passenger.so" >> ${TMPPLIST}
.endif
	${RM} ${STAGEDIR}${PREFIX}/bin/passenger-install-apache2-module ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/bin/passenger-install-apache2-module
	${RM} ${STAGEDIR}${PREFIX}/bin/passenger-install-nginx-module ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/bin/passenger-install-nginx-module

post-install-SYMLINK-on:
	${LN} -s ${GEM_NAME} ${STAGEDIR}${PREFIX}/${GEMS_DIR}/passenger

.include <bsd.port.mk>
