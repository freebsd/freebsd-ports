# Ports collection makefile for:	mod_webapp for Apache 2.x
# Date created:				Oct 11 2002
# Whom: 				Andy Gerweck <gerweck@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	mod_webapp
PORTVERSION=	4.1.12
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-tomcat-4.0/release/v${TOMCAT_RELEASE}/src/
PKGNAMESUFFIX=	-apache2
DISTNAME=	jakarta-tomcat-connectors-${CONNECTORS_RELEASE}-src
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	gerweck@yahoo.com

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/www/apache2:extract \
		${AUTOCONF}:${PORTSDIR}/devel/autoconf \
		${LIBTOOL}:${PORTSDIR}/devel/libtool
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache2

USE_GMAKE=	yes
ALL_TARGET=	lib-build apache-2.0-build

# Release information for distribution files.
TOMCAT_RELEASE=		${PORTVERSION}
CONNECTORS_RELEASE=	${PORTVERSION}

.include <bsd.port.pre.mk>

# Apache locations.
APXS?=		${LOCALBASE}/sbin/apxs
APACHECTL?=	${LOCALBASE}/sbin/apachectl
APR_LIB?=	${LOCALBASE}/lib/apache2/
APR_INCLUDE?=	${LOCALBASE}/include/apache2/
APACHE_MODULES?= libexec/apache2/
APR_SRC?=	${PORTSDIR}/www/apache2/work/httpd-*/srclib/apr
LIBTOOL?=	${LOCALBASE}/bin/libtool
AUTOCONF?=	${LOCALBASE}/bin/autoconf

# If the user's changed the modules directory, pack things correctly.
PLIST_SUB=	APACHE_MODULES=${APACHE_MODULES}

# Build options.
VERSION_2!=	${APACHECTL} -v | ${GREP} Apache/2 || true
.if empty(VERSION_2)
BROKEN=		"Either can't find apachectl or you seem to be using Apache 1.3, which is unsupported"
.endif
WRKSRC=		${WRKDIR}/${DISTNAME}/webapp
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apxs=${APXS} \
		--with-apr-lib=${APR_LIB} \
		--with-apr-include=${APR_INCLUDE} \
		--with-apr=${APR_SRC}

pre-configure:
	cd ${WRKSRC} && ${AUTOCONF}

pre-build:
	${MKDIR} ${WRKSRC}/build
	${MKDIR} ${WRKSRC}/build/objs

do-install:
	${APXS} -i -a ${WRKSRC}/apache-2.0/mod_webapp.so

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mod_webapp
	${INSTALL_MAN} ${WRKSRC}/INSTALL.txt ${PREFIX}/share/doc/mod_webapp
.endif

.include <bsd.port.post.mk>
