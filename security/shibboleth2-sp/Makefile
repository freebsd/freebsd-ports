# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	shibboleth-sp
PORTVERSION=	2.5.2
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://shibboleth.net/downloads/service-provider/${PORTVERSION}/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	C++ Shibboleth Service Provider (Internet2) for Apache

BUILD_DEPENDS=	boost-libs>=0:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	saml.8:${PORTSDIR}/security/opensaml2

MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	NOKEYGEN=YES
USE_LDCONFIG=	yes
USE_RC_SUBR=	shibboleth-sp

LATEST_LINK=	shibboleth2-sp

USERS=		shibd
GROUPS=		shibd

USE_APACHE=	22-24
USE_OPENSSL=	yes

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

SUB_LIST+=	SH=${SH}
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

SUB_LIST+=	SHIBD_USER=${USERS}
SUB_LIST+=	SHIBD_GROUP=${GROUPS}
PLIST_SUB+=	SHIBD_USER=${USERS}
PLIST_SUB+=	SHIBD_GROUP=${GROUPS}

CONFIGURE_ARGS+=	--localstatedir=/var --with-log4shib=${LOCALBASE}
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE} --with-xmltooling=${LOCALBASE}
CONFIGURE_ARGS+=	--disable-doxygen-doc

post-install:
	${CHOWN} -R ${USERS}:${GROUPS} /var/db/shibboleth ;\
	${CHOWN} -R ${USERS}:${GROUPS} /var/log/shibboleth ;\
       	${CHOWN} -R ${USERS}:${WWWGRP} /var/run/shibboleth ;\
       	${CHMOD} -R u=rwx,g=rx,o= /var/run/shibboleth

.include <bsd.port.post.mk>
