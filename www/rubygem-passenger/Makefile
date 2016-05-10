# Created by: Jacob Atzen <jatzen@gmail.com>
# $FreeBSD$

PORTNAME=	passenger
PORTVERSION=	5.0.28
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Modules for running Ruby on Rails and Rack applications

BUILD_DEPENDS=		${LOCALBASE}/bin/rake:devel/rubygem-rake

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE22}
USE_APACHE=	22+
.endif

LIB_DEPENDS+=	libuv.so:devel/libuv \
		libcurl.so:ftp/curl
BUILD_DEPENDS+= rubygem-rack16>=0:www/rubygem-rack16
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
		165s!true!false!' \
		${WRKSRC}/build/basics.rb
.if ${PORT_OPTIONS:NDEBUG}
	@${REINPLACE_CMD} \
		's!-DPASSENGER_DEBUG!-DNDEBUG!g' \
		${WRKSRC}/build/basics.rb
.endif

post-build:
.if ${PORT_OPTIONS:MAPACHE22}
	(CC=${CC} CXX=${CXX} ${WRKSRC}/bin/passenger-install-apache2-module --auto)
.endif

.if ${PORT_OPTIONS:MNGINX}
	(cd ${WRKSRC} && CC=${CC} CXX=${CXX} ${RAKE_BIN} nginx)
.endif

	${FIND} ${WRKSRC} -name '*.o' -delete
	${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
	( cd ${WRKSRC} && \
	${COPYTREE_SHARE} buildout ${STAGEDIR}${PREFIX}/${GEMS_DIR}/${PORTNAME}-${PORTVERSION} )
	${CHMOD} +x ${STAGEDIR}${PREFIX}/${GEMS_DIR}/${PORTNAME}-${PORTVERSION}/buildout/support-binaries/*
.if ${PORT_OPTIONS:MSYMLINK}
	${LN} -s ${PREFIX}/${GEM_LIB_DIR} ${STAGEDIR}${PREFIX}/${GEMS_DIR}/${PORTNAME}
.endif

.include <bsd.port.mk>
