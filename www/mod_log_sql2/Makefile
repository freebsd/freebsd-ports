# New ports collection makefile for:	mod_log_sql2
# Date created:				2001/11/22
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mod_log_sql
PORTVERSION=	1.101
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/${PORTNAME}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows Apache to log to a MySQL database

MAKE_JOBS_SAFE=  yes

LATEST_LINK=	mod_log_sql2
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}
SSL_PLIST=	""
APACHE2X=	""
PLIST_SUB+=	SSL=${SSL_PLIST} APACHE2X=${APACHE2X}

USE_MYSQL=	yes
USE_APACHE=	13+
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql"

.include <bsd.port.pre.mk>
.if defined(WITH_DBI) || exists(${LOCALBASE}/include/dbi/dbi.h)
CONFIGURE_ARGS+=	--with-dbi=${LOCALBASE}
LIB_DEPENDS+=		dbi.0:${PORTSDIR}/databases/libdbi
.endif
.   if ${APACHE_VERSION} == 13
WITHOUT_SSL=	YES
APACHE2X=	"@comment "
.   endif
.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-ssl
SSL_PLIST=	"@comment "
.else
.endif

.include <bsd.port.post.mk>
