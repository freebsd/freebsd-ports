# New ports collection makefile for:	mod_jk
# Date created:				Thu Apr 10 15:14:37 EDT 2003
# Whom:					Larry Lansing <lansil@fuzzynerd.com>
#
# $FreeBSD$
#

PORTNAME=	mod_jk
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	jakarta-tomcat-connectors/jk/release/v${PORTVERSION}/src
PKGNAMESUFFIX=	-apache2
DISTNAME=	jakarta-tomcat-connectors-jk-${PORTVERSION}-src

MAINTAINER=	lansil@fuzzynerd.com
COMMENT=	Apache 2.0 module for Tomcat

USE_APACHE=	yes
WITH_APACHE2=	yes
APACHE_CONF=	${PREFIX}/etc/apache2
WRKSRC=		${WRKDIR}/jakarta-tomcat-connectors-jk-${PORTVERSION}-src/jk/native

USE_GMAKE=	YES
USE_LIBTOOL=	YES
USE_AUTOCONF=	YES
USE_AUTOMAKE=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-apxs=${APXS}

do-install:
	${APXS} -i -A -n jk ${WRKSRC}/apache-2.0/mod_jk.so
	${SED} -e "s#%%APACHE_CONF%%#${APACHE_CONF}#g" ${FILESDIR}/mod_jk.conf.sample > ${WRKDIR}/mod_jk.conf.sample
	${INSTALL_DATA} ${WRKDIR}/mod_jk.conf.sample ${APACHE_CONF}
	${INSTALL_DATA} ${FILESDIR}/workers.properties.sample ${APACHE_CONF}

.include <bsd.port.mk>
