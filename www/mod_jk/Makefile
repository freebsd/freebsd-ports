# New ports collection makefile for:	mod_jk
# Date created:				Sun May 20 12:58:02 CEST 2001
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_jk
PORTVERSION=	1.2.3
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	jakarta-tomcat-connectors/jk/release/v${PORTVERSION}/src
DISTNAME=	jakarta-tomcat-connectors-jk-${PORTVERSION}-src

MAINTAINER=	girgen@pingpong.net
COMMENT=	Apache JK module for Tomcat

PATCH_DEPENDS=	${AUTOMAKE}:${PORTSDIR}/devel/automake
BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

APXS=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13
APACHE_CONF=	${LOCALBASE}/etc/apache${APACHE2}
WRKSRC=		${WRKDIR}/jakarta-tomcat-connectors-jk-${PORTVERSION}-src/jk/native

USE_GMAKE=	YES
USE_LIBTOOL=	YES
USE_AUTOCONF_VER=	253
USE_AUTOMAKE_VER=	15
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-apxs=${APXS}
APACHE2?=
APACHE_VER?=	1.3
PLIST_SUB=	APACHE2=${APACHE2}

post-patch:
	cd ${WRKSRC}; ${ACLOCAL}; ${LIBTOOLIZE}

do-install:
	${APXS} -i -A -n jk ${WRKSRC}/apache-${APACHE_VER}/mod_jk.so
	${SED} -e "s#%%APACHE_CONF%%#${APACHE_CONF}#g" ${FILESDIR}/mod_jk.conf.sample > ${WRKDIR}/mod_jk.conf.sample
	${INSTALL_DATA} ${WRKDIR}/mod_jk.conf.sample ${APACHE_CONF}
	${INSTALL_DATA} ${FILESDIR}/workers.properties.sample ${APACHE_CONF}

post-install:
	${CAT} ${PKGMESSAGE} | ${SED} "s|/usr/local|${PREFIX}|g"

.include <bsd.port.mk>
