# New ports collection makefile for:    apache mod_auth_mysql_another
# Date created:		2002/04/20
# Whom:			mbr@freebsd.org
#
# $FreeBSD$

PORTNAME=	mod_auth_mysql_another
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	modauthmysql
DISTNAME=       mod_auth_mysql
EXTRACT_SUFX=	.tgz

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Allows users to use MySQL databases for user authentication

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.10)
LIB_DEPENDS=   mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.else
.if exists(${LOCALBASE}/lib/mysql/libmysqlclient.so.14)
LIB_DEPENDS=   mysqlclient.14:${PORTSDIR}/databases/mysql41-client
.else
LIB_DEPENDS=   mysqlclient.12:${PORTSDIR}/databases/mysql40-client
.endif
.endif

.if exists(${LOCALBASE}/include/apache2/apr.h)
WITH_APACHE2=	yes
.endif

APXS=		${LOCALBASE}/sbin/apxs

.if defined(WITH_APACHE2)
APACHE_PORT=	${PORTSDIR}/www/apache2
APACHE_VER=	APACHE2
PLIST_SUB=	VER="2"
DSO=		mod_auth_mysql.la
.else
APACHE_PORT=	${PORTSDIR}/www/apache13
APACHE_VER=	APACHE1
PLIST_SUB=	VER=""
DSO=		mod_auth_mysql.so
.endif

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

post-patch:
	@${SED} 's|%%LOCALBASE%%|${LOCALBASE}|g;s|%%APXS%%|${APXS}|g;s|%%APACHE_VER%%|${APACHE_VER}|g;s|%%DSO%%|${DSO}|g' \
		${WRKDIR}/mod_auth_mysql/Makefile.orig > ${WRKDIR}/mod_auth_mysql/Makefile

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
