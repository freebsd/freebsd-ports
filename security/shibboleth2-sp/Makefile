# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	shibboleth-sp
PORTVERSION=	2.6.0
PORTREVISION=	4
CATEGORIES=	security www
MASTER_SITES=	http://shibboleth.net/downloads/service-provider/${PORTVERSION}/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	C++ Shibboleth Service Provider (Internet2) for Apache

LICENSE=	APACHE20

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libsaml.so:security/opensaml2 \
		libxmltooling-lite.so:devel/xmltooling \
		liblog4shib.so:devel/log4shib \
		libxerces-c.so:textproc/xerces-c3 \
		libxml-security-c.so:security/apache-xml-security-c

USES=		gmake tar:bzip2 ssl
GNU_CONFIGURE=	yes
MAKE_ENV=	NOKEYGEN=YES
USE_LDCONFIG=	yes
USE_RC_SUBR=	shibboleth-sp

USERS=		shibd
GROUPS=		shibd

INSTALL_TARGET=	install-strip

OPTIONS_GROUP=	CONNECT SESSION
OPTIONS_GROUP_CONNECT=FASTCGI APACHE
CONNECT_DESC=	Webserver modules

OPTIONS_GROUP_SESSION=ODBC MEMCACHED
SESSION_DESC=	Optional session storage

OPTIONS_DEFAULT=ODBC APACHE

# Descriptions
ODBC_DESC=	ODBC database backend - store sessions in a database
MEMCACHED_DESC=	Store sessions in memcached
FASTCGI_DESC=	FastCGI protocol support, e.g. for NGINX
APACHE_DESC=	Build Apache module

ODBC_CONFIGURE_ENABLE=	odbc
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

FASTCGI_CONFIGURE_WITH=	fastcgi=${LOCALBASE}
FASTCGI_LIB_DEPENDS=	libfcgi++.so:www/fcgi

MEMCACHED_CONFIGURE_WITH=	memcached=${LOCALBASE}
MEMCACHED_LIB_DEPENDS=		libmemcached.so:databases/libmemcached

OPTIONS_SUB=	yes

SUB_LIST+=	SH=${SH} WWWGRP=${WWWGRP}
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

SUB_LIST+=	SHIBD_USER=${USERS}
SUB_LIST+=	SHIBD_GROUP=${GROUPS}
PLIST_SUB+=	SHIBD_USER=${USERS}
PLIST_SUB+=	SHIBD_GROUP=${GROUPS}

CONFIGURE_ARGS+=	--localstatedir=/var --with-log4shib=${LOCALBASE}
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE} --with-xmltooling=${LOCALBASE}
CONFIGURE_ARGS+=	--disable-doxygen-doc

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE=	22+
.if "${APACHE_VERSION}" == 22
CONFIGURE_ARGS+=--disable-apache-24 --enable-apache-22 --with-apxs22=${APXS}
PLIST_SUB+=	WITH_APACHE_22=""
PLIST_SUB+=	WITH_APACHE_24="@comment "
.else
CONFIGURE_ARGS+=--disable-apache-22 --enable-apache-24 --with-apxs24=${APXS}
PLIST_SUB+=	WITH_APACHE_22="@comment "
PLIST_SUB+=	WITH_APACHE_24=""
.endif
.else
CONFIGURE_ARGS+=--disable-apache-24 --disable-apache-22
PLIST_SUB+=	WITH_APACHE_22="@comment "
PLIST_SUB+=	WITH_APACHE_24="@comment "
.endif

.include <bsd.port.post.mk>
