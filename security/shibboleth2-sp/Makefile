# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	shibboleth-sp
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://shibboleth.net/downloads/service-provider/${PORTVERSION}/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	C++ Shibboleth Service Provider (Internet2) for Apache

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libsaml.so:security/opensaml2 libodbc.so:databases/unixODBC \
		libxmltooling-lite.so:devel/xmltooling \
		liblog4shib.so:devel/log4shib \
		libxerces-c-3.1.so:textproc/xerces-c3 \
		libxml-security-c.so:security/apache-xml-security-c

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes
MAKE_ENV=	NOKEYGEN=YES
USE_LDCONFIG=	yes
USE_RC_SUBR=	shibboleth-sp

USERS=		shibd
GROUPS=		shibd

USE_APACHE=	22+
USE_OPENSSL=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} == 22
CONFIGURE_ARGS=	--enable-apache-22 --with-apxs22=${APXS}
PLIST_SUB+=	WITH_APACHE_22=""
PLIST_SUB+=	WITH_APACHE_24="@comment "
.else
CONFIGURE_ARGS=	--enable-apache-24 --with-apxs24=${APXS}
PLIST_SUB+=	WITH_APACHE_22="@comment "
PLIST_SUB+=	WITH_APACHE_24=""
.endif

SUB_LIST+=	SH=${SH} WWWGRP=${WWWGRP}
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

SUB_LIST+=	SHIBD_USER=${USERS}
SUB_LIST+=	SHIBD_GROUP=${GROUPS}
PLIST_SUB+=	SHIBD_USER=${USERS}
PLIST_SUB+=	SHIBD_GROUP=${GROUPS}

CONFIGURE_ARGS+=	--localstatedir=/var --with-log4shib=${LOCALBASE}
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE} --with-xmltooling=${LOCALBASE}
CONFIGURE_ARGS+=	--disable-doxygen-doc

.include <bsd.port.post.mk>
