# $FreeBSD$

PORTNAME=	facter
PORTVERSION=	3.14.16
CATEGORIES?=	sysutils
MASTER_SITES=	https://downloads.puppetlabs.com/facter/

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Cross-platform library for retrieving facts from OS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_DragonFly=	DragonFly is not supported upstream

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libleatherman_locale.so:devel/leatherman \
		liblibcpp-hocon.so:devel/cpp-hocon \
		libyaml-cpp.so:devel/yaml-cpp

CONFLICTS_INSTALL=	rubygem-facter-2*

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

USES=		cmake:noninja compiler:c++11-lib ssl
USE_LDCONFIG=	yes
USE_RUBY=	yes
CMAKE_ARGS+=	-DMAN_PATH=${MANPREFIX}/man
CMAKE_OFF=	ENABLE_CXX_WERROR

OPTIONS_DEFINE=	FACTER_JAVA
FACTER_JAVA_DESC=	Build with Java bindings for puppetserver
FACTER_JAVA_USE=	java=yes
FACTER_JAVA_VARS=	JAVA_BUILD=yes
FACTER_JAVA_CMAKE_ON=	-DJAVA_HOME=${JAVA_HOME}

OPTIONS_DEFAULT=	FACTER_JAVA

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/lib/src/facts/posix/collection.cc \
		${WRKSRC}/lib/src/util/config/posix/config.cc

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/specifications
	${INSTALL_DATA} ${WRKSRC}/.gemspec ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER}/specifications/${DISTNAME}.gemspec

test: build
	cd ${WRKSRC}/lib && bundle install --path vendor
	cd ${CONFIGURE_WRKSRC} && ${MAKE_CMD} test

.include <bsd.port.mk>
