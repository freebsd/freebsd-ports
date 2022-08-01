PORTNAME=	gvm
DISTVERSION=	22.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMESUFFIX=	-libs

MAINTAINER=	acm@FreeBSD.org
COMMENT=	libraries module for the GVM solution

LICENSE=	GPLv2+

BUILD_DEPENDS=	doxygen>0:devel/doxygen
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpgme.so:security/gpgme \
		libgpg-error.so:security/libgpg-error \
		libgnutls.so:security/gnutls \
		libuuid.so:misc/e2fsprogs-libuuid \
		libssh.so:security/libssh \
		libhiredis.so:databases/hiredis \
		libnet.so:net/libnet \
		libgcrypt.so:security/libgcrypt \
		libpaho-mqtt3a.so:net/libpaho-mqtt3
RUN_DEPENDS=	doxygen>0:devel/doxygen

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}

USES=		cmake gnome pkgconfig
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LDAP RADIUS

LDAP_CMAKE_ON=		-DBUILD_WITH_LDAP=1
LDAP_CMAKE_OFF=		-DBUILD_WITH_LDAP=0
LDAP_USE=		OPENLDAP=yes
RADIUS_CMAKE_ON=	-DBUILD_WITH_RADIUS=1
RADIUS_CMAKE_OFF=	-DBUILD_WITH_RADIUS=0
RADIUS_LIB_DEPENDS=	libfreeradius-client.so:net/freeradius-client

post-patch:
	@${REINPLACE_CMD} -e 's|2.25.0|1.45.6|g' ${WRKSRC}/util/libgvm_util.pc.in
	@${REINPLACE_CMD} -e 's|uuid>=2.25.0|uuid>=1.45.6|g' ${WRKSRC}/util/CMakeLists.txt
	@${REINPLACE_CMD} '31d' ${WRKSRC}/base/proctitle.c

.include <bsd.port.mk>
