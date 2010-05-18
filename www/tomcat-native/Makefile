# New ports collection makefile for:	tomcat-native
# Date created:			28 Feb 2008
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tomcat-native
PORTVERSION=	1.1.20
PORTREVISION=	2
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	tomcat/tomcat-connectors/native/${PORTVERSION}/source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Tomcat native library

LIB_DEPENDS=	apr-1:${PORTSDIR}/devel/apr1

WRKSRC=		${WRKDIR}/${DISTNAME}/jni/native

USE_OPENSSL=	yes
USE_JAVA=	yes
USE_LDCONFIG=	yes
JAVA_VERSION=	1.5+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apr=${LOCALBASE} \
		--with-java-home=${JAVA_HOME} \
		--with-ssl=${SSLBASE}

.include <bsd.port.mk>
