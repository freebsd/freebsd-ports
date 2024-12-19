PORTNAME=	gvm
DISTVERSIONPREFIX=	v
DISTVERSION=	22.22.0
PORTREVISION=	2
CATEGORIES=	security
PKGNAMESUFFIX=	-libs

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Libraries module for the GVM solution
WWW=		https://github.com/greenbone/gvm-libs

LICENSE=	GPLv2+

BUILD_DEPENDS=	doxygen>0:devel/doxygen
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libcjson.so:devel/libcjson \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libgpgme.so:security/gpgme \
		libgpg-error.so:security/libgpg-error \
		libhiredis.so:databases/hiredis \
		libnet.so:net/libnet \
		libpaho-mqtt3a.so:net/libpaho-mqtt3 \
		libssh.so:security/libssh \
		libuuid.so:misc/libuuid \
		libjson-glib-1.0.so:devel/json-glib \
		libcurl.so:ftp/curl
RUN_DEPENDS=	doxygen>0:devel/doxygen

USES=		cmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LDAP RADIUS

LDAP_CMAKE_ON=		-DBUILD_WITH_LDAP=1
LDAP_CMAKE_OFF=		-DBUILD_WITH_LDAP=0
LDAP_USES=		ldap
RADIUS_CMAKE_ON=	-DBUILD_WITH_RADIUS=1
RADIUS_CMAKE_OFF=	-DBUILD_WITH_RADIUS=0
RADIUS_LIB_DEPENDS=	libfreeradius-client.so:net/freeradius-client

post-patch:
	@${REINPLACE_CMD} -e 's|2.25.0|1.45.6|g' ${WRKSRC}/util/libgvm_util.pc.in
	@${REINPLACE_CMD} -e 's|uuid>=2.25.0|uuid>=1.45.6|g' ${WRKSRC}/util/CMakeLists.txt
	@${REINPLACE_CMD} '17d' ${WRKSRC}/base/proctitle.c

.include <bsd.port.mk>
