# New ports collection makefile for:	mod_jk
# Date created:				Sun May 20 12:58:02 CEST 2001
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_jk
PORTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://jakarta.apache.org/Builds/jakarta-tomcat/release/v${PORTVERSION}/src/ \
		http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
DISTNAME=	jakarta-tomcat-${PORTVERSION}-src

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13 \
		${JAVA_HOME}/bin/javac:${JAVA_PORT}
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13 \
		${TOMCAT_HOME}/lib/webserver.jar:${PORTSDIR}/www/jakarta-tomcat3

USE_GMAKE=	YES
MAKEFILE=	Makefile.freebsd
WRKSRC=		${WRKDIR}/jakarta-tomcat-${PORTVERSION}-src/src/native/mod_jk/apache1.3

APXS?=		${LOCALBASE}/sbin/apxs
JAVA_HOME?=	${LOCALBASE}/jdk1.3.1
JAVA_PORT?=	${PORTSDIR}/java/jdk13
APACHE_PORT?=	${PORTSDIR}/www/apache13
TOMCAT_HOME?=	${LOCALBASE}/jakarta-tomcat${PORTVERSION}

post-extract:
	${MV} ${WRKSRC}/Makefile.freebsd ${WRKSRC}/Makefile.freebsd.orig
	${SED} \
	-e "s#%%APXS%%#${APXS}#g" \
	-e "s#%%JAVA_HOME%%#${JAVA_HOME}#g" \
	${FILESDIR}/Makefile.freebsd \
	> ${WRKSRC}/Makefile.freebsd

do-install:
	${APXS} -i -A -n jk ${WRKSRC}/mod_jk.so
	${SED} -e "s#%%TOMCAT_HOME%%#${TOMCAT_HOME}#g" ${FILESDIR}/mod_jk.conf > ${WRKDIR}/mod_jk.conf
	${INSTALL_DATA} ${WRKDIR}/mod_jk.conf ${PREFIX}/etc/apache

.include <bsd.port.mk>
