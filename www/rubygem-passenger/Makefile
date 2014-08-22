# Created by: Jacob Atzen <jatzen@gmail.com>
# $FreeBSD$

PORTNAME=	passenger
PORTVERSION=	4.0.49
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Modules for running Ruby on Rails and Rack applications

USES+=		cpe

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
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE22}
USE_APACHE=	22+
.endif

.if ${PORT_OPTIONS:MNGINX}
NGINXVERSION!=	${PKG_INFO} -qO www/nginx-devel 2>/dev/null; ${ECHO_CMD}
.if empty(NGINXVERSION)
BUILD_DEPENDS+=	nginx:${PORTSDIR}/www/nginx
.else
BUILD_DEPENDS+=	nginx:${PORTSDIR}/www/nginx-devel
.endif
.endif

LIB_DEPENDS+=	libeio.so:${PORTSDIR}/devel/libeio \
		libev.so:${PORTSDIR}/devel/libev \
		libcurl.so:${PORTSDIR}/ftp/curl
BUILD_DEPENDS+=	rubygem-fastthread>=1.0.1:${PORTSDIR}/devel/rubygem-fastthread \
		rubygem-rack>=0:${PORTSDIR}/www/rubygem-rack \
		rubygem-daemon_controller>=1.2.0:${PORTSDIR}/devel/rubygem-daemon_controller
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_LIST+=	GEM_LIB_DIR=${GEM_LIB_DIR} RUBY=${RUBY}
SUB_FILES=	pkg-message

PLIST_FILES=	bin/passenger \
		bin/passenger-config \
		bin/passenger-install-apache2-module \
		bin/passenger-memory-stats \
		bin/passenger-status \
		bin/passenger-install-nginx-module

.if ${PORT_OPTIONS:MSYMLINK}
PLIST_FILES+=	${GEMS_DIR}/${PORTNAME}
SUB_LIST+=	PASSENGER_INSTALL_DIR="${PREFIX}/${GEMS_DIR}/${PORTNAME}"
.else
SUB_LIST+=	PASSENGER_INSTALL_DIR="${PREFIX}/${GEM_LIB_DIR}"
.endif

pre-patch:
.if ${PORT_OPTIONS:MNGINX}
	@${ECHO_CMD}
	@${ECHO_CMD} "Do not forget compile www/nginx"
	@${ECHO_CMD} "with PASSENGER_MODULE support"
	@${ECHO_CMD}
.endif

	@${REINPLACE_CMD} \
		's!-Wall!!g; \
		s!gcc!${CC}!g; \
		s!g++!${CXX}!g; \
		s!#{PlatformInfo.debugging_cflags}!${CFLAGS}!g; \
		s!-O2!!g; \
		s! -feliminate-unused-debug-symbols -feliminate-unused-debug-types!!g; \
		204,206s!true!false!' \
		${WRKSRC}/build/basics.rb
.if ${PORT_OPTIONS:NDEBUG}
	@${REINPLACE_CMD} \
		's!-DPASSENGER_DEBUG!-DNDEBUG!g' \
		${WRKSRC}/build/basics.rb
.endif
	@${REINPLACE_CMD} \
		's!#{LIBEV_LIBS}!-L${LOCALBASE}/lib -lev!g' \
		${WRKSRC}/build/agents.rb
	@${REINPLACE_CMD} \
		's!-Iext/libev!!; \
		s!/usr/include/libev!${LOCALBASE}/include!; \
		s!-lev!-L${LOCALBASE}/lib -lev!; \
		s!-Iext/libeio!!; \
		s!/usr/include/libeio!${LOCALBASE}/include!; \
		s!-leio!-L${LOCALBASE}/lib -leio!' \
		${WRKSRC}/build/common_library.rb
	@${REINPLACE_CMD} \
		's!-lpthread!${PTHREAD_LIBS}!g' \
		${WRKSRC}/lib/phusion_passenger/platform_info/cxx_portability.rb

post-build:
.if ${PORT_OPTIONS:MAPACHE22}
	(CC=${CC} CXX=${CXX} ${WRKSRC}/bin/passenger-install-apache2-module --auto)
.endif

.if ${PORT_OPTIONS:MNGINX}
	(cd ${WRKSRC} && CC=${CC} CXX=${CXX} ${RAKE_BIN} nginx)
.endif
.if ${PORT_OPTIONS:MSYMLINK}
	${LN} -s ${GEM_LIB_DIR} ${STAGE}${PREFIX}/${GEMS_DIR}/${PORTNAME}
.endif

	${FIND} ${WRKSRC} -name '*.o' -delete
	${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
	( cd ${WRKSRC} && \
	${COPYTREE_SHARE} buildout ${STAGEDIR}${PREFIX}/${GEMS_DIR}/${PORTNAME}-${PORTVERSION} )
	${CHMOD} +x ${STAGEDIR}${PREFIX}/${GEMS_DIR}/${PORTNAME}-${PORTVERSION}/buildout/agents/*

.include <bsd.port.mk>
