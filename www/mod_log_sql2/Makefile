# New ports collection makefile for:	mod_log_sql2
# Date created:				2001/11/22
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mod_log_sql
PORTVERSION=	1.97
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows Apache to log to a MySQL database

GNU_CONFIGURE=	yes
USE_MYSQL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}
SSL_PLIST=	"@comment "
PLIST_SUB+=	SSL=${SSL_PLIST}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
.if defined(WITH_SSL)
.    if ${AP_VER} != 2
BROKEN=		"SSL support needs apache2"
.    endif
.if !exists(${LOCALBASE}/include/apache2/mod_ssl.h)
BROKEN=		"Please recompile apache2 with SSL support"
.endif
CONFIGURE_ARGS+=	--enable-ssl
SSL_PLIST=	""
.endif
.include <bsd.port.post.mk>
