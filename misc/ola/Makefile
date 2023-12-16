PORTNAME=	ola
DISTVERSION=	0.10.9
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	https://github.com/OpenLightingProject/ola/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Lighting Architecture: framework for lighting control information
WWW=		https://www.openlighting.org/ola/

LICENSE=	GPLv2+

LIB_DEPENDS=	libavahi-common.so:net/avahi-app \
		libftdi1.so:devel/libftdi1 \
		libmicrohttpd.so:www/libmicrohttpd \
		libprotobuf.so:devel/protobuf3 \
		libuuid.so:misc/e2fsprogs-libuuid
TEST_DEPENDS=	cppunit>0:devel/cppunit

USES=		bison gmake libtool localbase pkgconfig
USE_LDCONFIG=	yes

LDFLAGS+=	-lprotobuf # workaround for https://github.com/OpenLightingProject/ola/issues/1871

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-unittests --disable-examples

TEST_TARGET=	check
INSTALL_TARGET=	install-strip

do-test: # 1 test fails, see https://github.com/OpenLightingProject/ola/issues/1872
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ./configure ${CONFIGURE_ARGS} --enable-unittests && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${TEST_TARGET}

.include <bsd.port.mk>
