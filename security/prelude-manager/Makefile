# New ports collection makefile for:	prelude-manager
# Date created:			Sun Aug 4 19:31:17 CEST 2002
# Whom:				Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$

PORTNAME=	prelude-manager
PORTVERSION=	0.8.10
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.org/download/releases/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Prelude Network Intrusion Detection System central logging point

LIB_DEPENDS+=	prelude.1:${PORTSDIR}/security/libprelude \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc \
			--program-prefix="" --localstatedir=/var

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-openssl
.else
USE_OPENSSL=		YES
CONFIGURE_ARGS+=	--enable-openssl
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		YES
CONFIGURE_ARGS+=	--enable-mysql
PLIST_SUB+=		MYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		MYSQL="@comment "
.endif

.if defined(WITH_POSTGRES)
LIB_DEPENDS+=		pq.3:${PORTSDIR}/databases/postgresql-client
CONFIGURE_ARGS+=	--enable-pgsql
PLIST_SUB+=		PGSQL=""
.else
CONFIGURE_ARGS+=	--disable-pgsql
PLIST_SUB+=		PGSQL="@comment "
.endif

post-patch:
	@${ECHO} ""
	@${ECHO} "*---------------------------------------------------------------------------*"
	@${ECHO} "Options:"
	@${ECHO} ""
	@${ECHO} "      WITHOUT_SSL=yes         Disable SSL support"
	@${ECHO} "      WITH_MYSQL=yes          Enable MySQL support"
	@${ECHO} "      WITH_POSTGRES=yes       Enable PostreSQL support"
	@${ECHO} "*---------------------------------------------------------------------------*"
	@${ECHO} ""

.include <bsd.port.mk>
