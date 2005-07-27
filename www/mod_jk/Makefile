# New ports collection makefile for:	mod_jk
# Date created:				Sun May 20 12:58:02 CEST 2001
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_jk
PORTVERSION=	1.2.14.1
PORTREVISION=	1
PORTEPOCH?=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	tomcat-connectors/jk/source/jk-${PORTVERSION:S/.1$//}
DISTNAME=	jakarta-tomcat-connectors-${PORTVERSION}-src

MAINTAINER?=	girgen@FreeBSD.org
COMMENT?=	Apache JK module for connecting to Tomcat using AJP1X

USE_APACHE=	YES

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/apache2/apr.h)
WITH_APACHE2=	YES
.endif

.if defined(WITH_APACHE2)
APACHE_VER=	2.0
APACHE2=	2
PLIST_SUB=	APACHE2=2
PKGNAMESUFFIX=	-apache2
.else
APACHE_VER=	1.3
APACHE2=
PLIST_SUB=	APACHE2=
.endif

APACHE_CONF=	${LOCALBASE}/etc/apache${APACHE2}
WRKSRC=		${WRKDIR}/jakarta-tomcat-connectors-${PORTVERSION}-src/jk/native

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-apxs=${APXS}

do-install:
	${APXS} -i -n jk ${WRKSRC}/apache-${APACHE_VER}/mod_jk.so
	- ${APXS} -e -A -n jk ${WRKSRC}/apache-${APACHE_VER}/mod_jk.so
	${SED} -e "s#%%APACHE_CONF%%#${APACHE_CONF}#g" ${FILESDIR}/mod_jk.conf.sample \
		 > ${WRKDIR}/mod_jk.conf.sample
	${INSTALL_DATA} ${WRKDIR}/mod_jk.conf.sample ${APACHE_CONF}
	${INSTALL_DATA} ${FILESDIR}/workers.properties.sample ${APACHE_CONF}

post-install:
	${CAT} ${PKGMESSAGE} | ${SED} "s|/usr/local|${PREFIX}|g"

.include <bsd.port.post.mk>
