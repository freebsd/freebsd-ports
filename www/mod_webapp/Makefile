# Ports collection makefile for:	mod_webapp for Apache 1.3.x
# Date created:				Jun 12 2003
# Whom: 				Andre Sachs <asachs@uunet.co.za>
#
# $FreeBSD$
#

PORTNAME=	mod_webapp
PORTVERSION=	4.1.24
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	builds/jakarta-tomcat-4.0/release/v${TOMCAT_RELEASE}/src
DISTNAME=	jakarta-tomcat-connectors-${CONNECTORS_RELEASE}-src
DIST_SUBDIR=	mod_webapp

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module mounts Tomcat web applications

BUILD_DEPENDS=	${NONEXISTANT}:${PORTSDIR}/devel/apr:configure

USE_REINPLACE=	yes
USE_APACHE=	yes
WANT_AUTOCONF_VER=253
WANT_LIBTOOL_VER=13
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

# Release information for distribution files.
TOMCAT_RELEASE=		${PORTVERSION}
CONNECTORS_RELEASE=	${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not build on amd64 or ia64"
.endif

# Apache locations.
APACHECTL?=	${LOCALBASE}/sbin/apachectl
APR_LIB?=	${LOCALBASE}/lib/
APR_INCLUDE?=	${LOCALBASE}/include/apr-${APR_MAJORVER}/
APACHE_MODULES?=libexec/apache
APR_VER!=	cd ${PORTSDIR}/devel/apr && ${MAKE} -V PORTVERSION
APR_WRKSRC!=	cd ${PORTSDIR}/devel/apr && ${MAKE} -V WRKSRC
APR_MAJORVER=	${APR_VER:C/\..*//g}
APR_SRC=	${APR_WRKSRC}/apr-${APR_VER}
AUTOCONF?=	${LOCALBASE}/bin/autoconf

# If the user's changed the modules directory, pack things correctly.
PLIST_SUB=	APACHE_MODULES=${APACHE_MODULES}

# Build options.
APACHE_VERSION=	1.3.6
WRKSRC=		${WRKDIR}/${DISTNAME}/webapp
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apxs=${APXS} \
		--with-apr-lib=${APR_LIB} \
		--with-apr-include=${APR_INCLUDE} \
		--with-apr=${APR_SRC} \
		--without-ant

post-patch:
	${REINPLACE_CMD} -e 's/apr-config/apr-${APR_MAJORVER}-config/g' \
		${WRKSRC}/support/wa_apr.m4

pre-configure:
	cd ${WRKSRC} && ${AUTOCONF}

pre-build:
	${MKDIR} ${WRKSRC}/build
	${MKDIR} ${WRKSRC}/build/objs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apache-1.3/mod_webapp.so \
	    ${PREFIX}/libexec/apache

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/INSTALL.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
