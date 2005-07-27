# New ports collection makefile for:	mod_jk2
# Date created:				Thu May 29 01:24:15 CEST 2003
# Whom:					Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	mod_jk2
PORTVERSION=	2.0.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	tomcat-connectors/jk2/source
DISTNAME=	jakarta-tomcat-connectors-jk2-${PORTVERSION}-src

MAINTAINER?=	girgen@FreeBSD.org
COMMENT?=	Apache JK2 module for connecting to Tomcat using AJP1X

DEPRECATED=	"JK2 is officially unsupported, no further development will take place."

USE_APACHE=	yes
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-apxs${APACHE2}=${APXS}

ALL_TARGET=	jk2-build-apxs
INSTALL_TARGET=	jk2-install-apxs

WRKSRC=		${WRKDIR}/jakarta-tomcat-connectors-jk2-${PORTVERSION}-src/jk/native2

PKGMESSAGE=	${WRKDIR}/.pkg-message

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/apache2/apr.h)
WITH_APACHE2=	yes
.endif

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

.if ${ARCH} == "sparc64" && !defined(WITH_APACHE2)
BROKEN=		"Fails to link on sparc64"
.endif

.if defined(WITH_APACHE2)
APACHE2=	2
PLIST_SUB=	APACHE2=2
PKGNAMESUFFIX=	-apache2
APACHE=		apache2
.else
APACHE2=
PLIST_SUB=	APACHE2=
APACHE=		apache13
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/devel/apr:patch
APR_DIR=	`cd ${PORTSDIR}/devel/apr && make -V WRKDIR`
APR_VERSION=	`cd ${PORTSDIR}/devel/apr && make -V PORTVERSION`
CONFIGURE_ARGS+=--with-apr=${APR_DIR}/apr-${APR_VERSION} \
		--with-apr-util=${APR_DIR}/apr-util-${APR_VERSION}
.endif

post-patch:
	@ ${SED} "s|/usr/local|${PREFIX}|g" \
	< ${MASTERDIR}/pkg-message \
	> ${PKGMESSAGE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/../conf/workers2.properties \
		${PREFIX}/etc/apache${APACHE2}/workers2.properties.sample
	- ${APXS} -e -A -n jk2 mod_jk2.so
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
