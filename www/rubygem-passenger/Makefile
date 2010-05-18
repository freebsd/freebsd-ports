# Ports collection makefile for:	rubygem-passenger
# Date created:				Dec 18, 2008
# Whom:					Jacob Atzen <jatzen@gmail.com>
#
# $FreeBSD$

PORTNAME=	passenger
PORTVERSION=	2.2.11
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RF
PKGNAMEPREFIX=	rubygem-

MAINTAINER=	jatzen@gmail.com
COMMENT=	Modules for running Ruby on Rails and Rack applications

OPTIONS=	APACHEPORT	"Use apache22"		on \
		NGINXPORT	"Use nginx"		off

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.options.mk>

.if defined(WITH_APACHEPORT) && defined(WITH_NGINXPORT)
IGNORE=		supports only one web-server: apache22 or nginx. \
		Please 'make config' again
.endif

.if !defined(WITHOUT_APACHEPORT)
USE_APACHE=	2.2+
.endif

.if defined(WITH_NGINXPORT)
BUILD_DEPENDS+=	nginx>=0.7.64:${PORTSDIR}/www/nginx
.endif

BUILD_DEPENDS+=	rubygem-fastthread>=1.0.1:${PORTSDIR}/devel/rubygem-fastthread \
		rubygem-rack>=1.0.0:${PORTSDIR}/www/rubygem-rack

SUB_LIST+=	GEM_LIB_DIR=${GEM_LIB_DIR} RUBY=${RUBY}
SUB_FILES=	pkg-message

PLIST_FILES=	bin/passenger-config \
		bin/passenger-install-apache2-module \
		bin/passenger-make-enterprisey \
		bin/passenger-memory-stats \
		bin/passenger-spawn-server \
		bin/passenger-status \
		bin/passenger-stress-test \
		bin/passenger-install-nginx-module

pre-patch:
.if defined(WITH_NGINXPORT)
	@${ECHO_CMD}
	@${ECHO_CMD} "Do not forget compile www/nginx"
	@${ECHO_CMD} "with PASSENGER_MODULE support"
	@${ECHO_CMD}
.endif

post-install:
	${REINPLACE_CMD} 's!g++!${CXX}!; \
		s!gcc!${CC}!;' \
		${PREFIX}/${GEM_LIB_DIR}/Rakefile
	${REINPLACE_CMD} '377s!-g!${CXXFLAGS}!; \
		s!-lpthread!${PTHREAD_LIBS}!g' \
		${PREFIX}/${GEM_LIB_DIR}/lib/phusion_passenger/platform_info.rb

.if !defined(WITHOUT_APACHEPORT)
	(${PREFIX}/bin/passenger-install-apache2-module --auto)
	@${CAT} ${PKGMESSAGE}
.endif

.if defined(WITH_NGINXPORT)
	${REINPLACE_CMD} '62d;65d' \
		${PREFIX}/${GEM_LIB_DIR}/Rakefile
	(cd ${PREFIX}/${GEM_LIB_DIR} && ${RAKE_BIN})
.endif

	${FIND} ${PREFIX}/${GEM_LIB_DIR} -name '*.o' -delete
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -name '*.bak' -delete

.include <bsd.port.mk>
