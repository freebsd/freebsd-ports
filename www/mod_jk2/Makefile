# New ports collection makefile for:	mod_jk2
# Date created:				Thu May 29 01:24:15 CEST 2003
# Whom:					Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	mod_jk2
PORTVERSION=	2.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	tomcat-connectors/jk2/source
DISTNAME=	jakarta-tomcat-connectors-jk2-${PORTVERSION}-src

MAINTAINER?=	girgen@pingpong.net
COMMENT?=	Apache JK2 module for connecting to Tomcat using AJP1X

USE_APACHE=	yes
USE_GMAKE=	YES
USE_LIBTOOL_VER=	13
USE_AUTOCONF_VER=	253
USE_AUTOMAKE_VER=	15
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-apxs${APACHE2}=${APXS}
ALL_TARGET=	jk2-build-apxs

WRKSRC=		${WRKDIR}/jakarta-tomcat-connectors-jk2-${PORTVERSION}-src/jk/native2

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/apache2/apr.h)
WITH_APACHE2=	yes
.endif

.if defined(WITH_APACHE2)
APACHE2=	2
PLIST_SUB=	APACHE2=2
PKGNAMESUFFIX=	-apache2
APACHE=		apache2
AP_EXT=		la
.else
APACHE2=
PLIST_SUB=	APACHE2=
AP_EXT=		so
APACHE=		apache13
.endif

pre-patch:	build-depends

post-patch:
	cd ${WRKSRC}; ${ACLOCAL}; ${LIBTOOLIZE}

do-install:
	cd ${WRKSRC}/server/${APACHE} ;\
		${GMAKE} -f Makefile.apxs install ;\
		${APXS} -e -A -n jk2 mod_jk2.${AP_EXT}

.include <bsd.port.post.mk>
