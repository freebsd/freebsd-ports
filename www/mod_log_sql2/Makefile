# New ports collection makefile for:	mod_log_sql2
# Date created:				2001/11/22
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mod_log_sql
PORTVERSION=	1.100
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/${PORTNAME}/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows Apache to log to a MySQL database

LATEST_LINK=	mod_log_sql2
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
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
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
.   if ${AP_VER} == 13
WITHOUT_SSL=	YES
.   endif
.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-ssl
SSL_PLIST=	"@comment "
.else
.if !exists(${LOCALBASE}/include/apache2/mod_ssl.h)
BROKEN=		"Please recompile apache2 with SSL support"
.endif
.endif

.include <bsd.port.post.mk>
