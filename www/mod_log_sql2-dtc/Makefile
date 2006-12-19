# New ports collection makefile for:	mod_log_sql2-dtc
# Date created:				2006/11/20
# Whom:					Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$

PORTNAME=	mod_log_sql
PORTVERSION=	1.100
PORTREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/${PORTNAME}/
PKGNAMESUFFIX=	-dtc

MAINTAINER=	scrappy@freebsd.org
COMMENT=	Allows Apache to log to a MySQL database

LATEST_LINK=	mod_log_sql2
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_APACHE=	2.2+
CONFIGURE_ARGS+=	--with-apxs=${APXS}
SSL_PLIST=	""
PLIST_SUB+=	SSL=${SSL_PLIST}

USE_MYSQL=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql"

.include <bsd.port.pre.mk>
.if defined(WITH_DBI) || exists(${LOCALBASE}/include/dbi/dbi.h)
CONFIGURE_ARGS+=	--with-dbi=${LOCALBASE}
LIB_DEPENDS+=		dbi.0:${PORTSDIR}/databases/libdbi
.endif
.include "${PORTSDIR}/www/apache20/Makefile.modules.3rd"
.   if ${AP_VER} == 13
WITHOUT_SSL=	YES
.   endif
.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-ssl
SSL_PLIST=	"@comment "
.else
.if !exists(${LOCALBASE}/include/apache2/mod_ssl.h)
BROKEN=		Please recompile apache2 with SSL support
.endif
.endif

.include <bsd.port.post.mk>
