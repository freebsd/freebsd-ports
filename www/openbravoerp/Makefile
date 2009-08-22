# New ports collection makefile for:    openbravoerp
# Date created:         		2 Nov 2008
# Whom:                 		loader@freebsdmall.com
#
# $FreeBSD$
#

PORTNAME=	openbravoerp
PORTVERSION=	2.40
CATEGORIES=	www java
MASTER_SITES=	SF/openbravo/09-openbravo-old-installers/${PORTVERSION}
DISTNAME=	OpenbravoERP_${PORTVERSION}-freebsd6${PLATFORM}-installer
EXTRACT_SUFX=	.bin
EXTRACT_ONLY=	#

MAINTAINER=	loader@freebsdmall.com
COMMENT=	Openbravo ERP is a Web based ERP

ONLY_FOR_ARCHS=	i386 amd64
USE_JAVA=	yes
JAVA_VERSION=	1.6+

USE_PGSQL=	yes
WANT_PGSQL_VER=	83
NO_BUILD=	yes
IS_INTERACTIVE=	yes
NO_PACKAGE=	too interactive

APP_HOME=	OpenbravoERP${PORTVERSION}
PLIST_SUB+=	ERP=${APP_HOME}

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
PLATFORM=	
.elif ${ARCH} == amd64
PLATFORM=	-x64
.else
IGNORE=	unsupported OS release
.endif

.if ${OSVERSION} >= 700000
LIB_DEPENDS+=	c.6:${PORTSDIR}/misc/compat6x
.endif

BUILD_DEPENDS+=	${LOCALBASE}/tomcat5.5/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
BUILD_DEPENDS+=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/apache-ant

pre-everything::
	@${SH} ${PKGINSTALL} ${PORTNAME} DBWARNING

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
	@${CHMOD} +x ${WRKSRC}/${DISTFILES}

pre-su-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} PGUSER=${PGUSER} PGGROUP=${PGGROUP} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

do-install:
	@cd ${WRKSRC} && ${WRKSRC}/${DISTFILES} --mode text --prefix ${LOCALBASE}/${APP_HOME}

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>

