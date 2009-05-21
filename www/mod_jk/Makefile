# New ports collection makefile for:	mod_jk
# Date created:				Sun May 20 12:58:02 CEST 2001
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_jk
PORTVERSION=	1.2.27
PORTREVISION=	0
PORTEPOCH?=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	tomcat/tomcat-connectors/jk/source/jk-${PORTVERSION}
DISTNAME=	tomcat-connectors-${PORTVERSION}-src

MAINTAINER?=	girgen@FreeBSD.org
COMMENT?=	Apache JK module for connecting to Tomcat using AJP1X

MAKE_JOBS_SAFE=  yes

USE_APACHE?=	1.3+

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
PKGNAMESUFFIX=	-ap2
APACHE_VER=	2.0
.else
APACHE_VER=	1.3
.endif

WRKSRC=		${WRKDIR}/tomcat-connectors-${PORTVERSION}-src/native

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-apxs=${APXS}

SUB_FILES+=	mod_jk.conf.sample pkg-message

do-install:
	${APXS} -i -n jk ${WRKSRC}/apache-${APACHE_VER}/mod_jk.so
	- ${APXS} -e -A -n jk ${WRKSRC}/apache-${APACHE_VER}/mod_jk.so
	${INSTALL_DATA} ${WRKDIR}/mod_jk.conf.sample ${LOCALBASE}/${APACHEETCDIR}
	${INSTALL_DATA} ${FILESDIR}/workers.properties.sample ${LOCALBASE}/${APACHEETCDIR}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
