# New ports collection makefile for:	mod_log_sql2-dtc
# Date created:				2006/11/20
# Whom:					Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$

PORTNAME=	mod_log_sql
PORTVERSION=	1.101
PORTREVISION=	1
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/${PORTNAME}/
PKGNAMESUFFIX=	-dtc

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows Apache to log to a MySQL database

MAKE_JOBS_SAFE=	yes

LATEST_LINK=	mod_log_sql2-dtc
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_APACHE=	22+
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

.include <bsd.port.post.mk>
