PORTNAME=	ecal
DISTVERSIONPREFIX=	v
DISTVERSION=	5.13.3
PORTREVISION=	8
CATEGORIES=	net devel

BROKEN=		incompatible with asio >= 1.33

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Enhanced Communication Abstraction Layer
WWW=		https://eclipse-ecal.github.io/ecal/index.html \
		https://github.com/eclipse-ecal/ecal

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_armv7=	link fails: undefined reference due to --no-allow-shlib-undefined: absl::lts_20230125::hash_internal::CityHash32(char const*, unsigned int)
BROKEN_i386=	link fails: undefined reference due to --no-allow-shlib-undefined: absl::lts_20230125::hash_internal::CityHash32(char const*, unsigned int)
BROKEN_powerpc=	link fails: undefined reference due to --no-allow-shlib-undefined: absl::lts_20230125::hash_internal::CityHash32(char const*, unsigned int)

BUILD_DEPENDS=	asio>0:net/asio \
		termcolor>0:devel/termcolor
LIB_DEPENDS=	libabsl_hash.so:devel/abseil \
		libcurl.so:ftp/curl \
		libfmt.so:devel/libfmt \
		libfineftp-server.so:ftp/fineftp-server \
		libftxui-component.so:devel/ftxui \
		libhdf5.so:science/hdf5 \
		libprotobuf.so:devel/protobuf \
		libqwt.so:x11-toolkits/qwt6@qt5 \
		libspdlog.so:devel/spdlog \
		libsysinfo.so:devel/libsysinfo \
		libtinyxml2.so:textproc/tinyxml2 \
		libyaml-cpp.so:devel/yaml-cpp
		# binaries aren't linked with libfineftp-server.so, see https://github.com/continental/ecal/issues/381; same with libcurl.so

USES=		cmake compiler:c++17-lang desktop-file-utils localbase:ldflags pkgconfig qt:5 shared-mime-info
USE_QT=		concurrent core gui widgets buildtools:build qmake:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	eclipse-ecal
GH_TUPLE=	eclipse-ecal:tcp_pubsub:b0393e4:tcp_pubsub/thirdparty/tcp_pubsub/tcp_pubsub \
		brofield:simpleini:9b3ed7e:simpleini/thirdparty/simpleini/simpleini \
		steinwurf:recycle:c542570:recycle/thirdparty/recycle/recycle \
		xguerin:tclap:349170a:tclap/thirdparty/tclap/tclap

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_SAMPLES \
		ECAL_THIRDPARTY_BUILD_SPDLOG ECAL_THIRDPARTY_BUILD_TINYXML2 ECAL_THIRDPARTY_BUILD_FINEFTP ECAL_THIRDPARTY_BUILD_TERMCOLOR \
		ECAL_THIRDPARTY_BUILD_FTXUI ECAL_THIRDPARTY_BUILD_GTEST ECAL_THIRDPARTY_BUILD_PROTOBUF \
		ECAL_THIRDPARTY_BUILD_CURL ECAL_THIRDPARTY_BUILD_HDF5 ECAL_THIRDPARTY_BUILD_YAML-CPP ECAL_THIRDPARTY_BUILD_UDPCAP \
		CPACK_PACK_WITH_INNOSETUP
CMAKE_ARGS=	-DGIT_REVISION_MAJOR=${DISTVERSION:R:R} \
		-DGIT_REVISION_MINOR=${DISTVERSION:R:E} \
		-DGIT_REVISION_PATCH=${DISTVERSION:E} \
		-Dasio_INCLUDE_DIR=${LOCALBASE}/include \
		-Dqwt_INCLUDE_DIR=${LOCALBASE}/include/qt5/qwt6 \
		-Dqwt_LIBRARY=${LOCALBASE}/lib/qt5/libqwt.so

CXXFLAGS+=	-pthread # see https://github.com/eclipse-ecal/ecal/issues/933
LDFLAGS+=	-labsl_hash -labsl_log_internal_message -labsl_log_internal_nullguard -labsl_spinlock_wait
USE_CXXSTD=	c++17

PLIST_SUB=	VERSION=${DISTVERSION}

CONFLICTS_BUILD=	tclap simpleini # epub isn't compatible with tclap-1.4rc1, epub isn't compatible with simpleini, because some header isn't installed

post-install: # not sure why isn't this installed automatically
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/libsys_core.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
