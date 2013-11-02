# Created by: Jacob Atzen <jatzen@gmail.com>
# $FreeBSD$

PORTNAME=	passenger
PORTVERSION=	4.0.23
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Modules for running Ruby on Rails and Rack applications

OPTIONS_DEFINE=	DEBUG SYMLINK
OPTIONS_SINGLE=	SERVER
OPTIONS_SINGLE_SERVER=	APACHE22 NGINX
APACHE22_DESC=	Build with apache22 support
NGINX_DESC=	Build with nginx support
SYMLINK_DESC= 	Create passenger symlink
OPTIONS_DEFAULT=	APACHE22

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE22}
USE_APACHE=	22+
.endif

.if ${PORT_OPTIONS:MNGINX}
NGINXVERSION!=	${PKG_INFO} -qO www/nginx-devel 2>/dev/null || true
.if empty(NGINXVERSION)
BUILD_DEPENDS+=	nginx:${PORTSDIR}/www/nginx
.else
BUILD_DEPENDS+=	nginx:${PORTSDIR}/www/nginx-devel
.endif
.endif

LIB_DEPENDS+=	eio:${PORTSDIR}/devel/libeio \
		ev:${PORTSDIR}/devel/libev \
		curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS+=	rubygem-fastthread>=1.0.1:${PORTSDIR}/devel/rubygem-fastthread \
		rubygem-rack>=0:${PORTSDIR}/www/rubygem-rack \
		rubygem-daemon_controller>=1.1.0:${PORTSDIR}/devel/rubygem-daemon_controller
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

post-install:
	@${REINPLACE_CMD} \
		's!-Wall!!g; \
		s!gcc!${CC}!g; \
		s!g++!${CXX}!g; \
		s!#{PlatformInfo.debugging_cflags}!${CFLAGS}!g; \
		s!-O2!!g; \
		s! -feliminate-unused-debug-symbols -feliminate-unused-debug-types!!g; \
		193,195s!true!false!' \
		${PREFIX}/${GEM_LIB_DIR}/build/basics.rb
.if ${PORT_OPTIONS:NDEBUG}
	@${REINPLACE_CMD} \
		's!-DPASSENGER_DEBUG!-DNDEBUG!g' \
		${PREFIX}/${GEM_LIB_DIR}/build/basics.rb
.endif
	@${REINPLACE_CMD} \
		's!#{LIBEV_LIBS}!-L${LOCALBASE}/lib -lev!g' \
		${PREFIX}/${GEM_LIB_DIR}/build/agents.rb
	@${REINPLACE_CMD} \
		's!-Iext/libev!!; \
		s!/usr/include/libev!${LOCALBASE}/include!; \
		s!-lev!-L${LOCALBASE}/lib -lev!; \
		s!-Iext/libeio!!; \
		s!/usr/include/libeio!${LOCALBASE}/include!; \
		s!-leio!-L${LOCALBASE}/lib -leio!' \
		${PREFIX}/${GEM_LIB_DIR}/build/common_library.rb
	@${REINPLACE_CMD} \
		's!-lpthread!${PTHREAD_LIBS}!g' \
		${PREFIX}/${GEM_LIB_DIR}/lib/phusion_passenger/platform_info/cxx_portability.rb
.if ${PORT_OPTIONS:MAPACHE22}
	(${PREFIX}/bin/passenger-install-apache2-module --auto)
	@${CAT} ${PKGMESSAGE}
.endif

.if ${PORT_OPTIONS:MNGINX}
	(cd ${PREFIX}/${GEM_LIB_DIR} && ${RAKE_BIN} nginx)
.endif

	${FIND} ${PREFIX}/${GEM_LIB_DIR} -name '*.o' -delete
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -name '*.bak' -delete
.if ${PORT_OPTIONS:MSYMLINK}
	${LN} -s ${PREFIX}/${GEM_LIB_DIR} ${PREFIX}/${GEMS_DIR}/${PORTNAME}
.endif

.include <bsd.port.mk>
