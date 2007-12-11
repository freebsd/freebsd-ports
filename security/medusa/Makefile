# New ports collection makefile for:	medusa
# Date created:		2006-05-01
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	medusa
PORTVERSION=	1.4
CATEGORIES=	security
MASTER_SITES=	http://www.foofus.net/jmk/tools/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A speedy, massively parallel, modular, login brute-forcer

OPTIONS=	SVN "Enable Subversion module" off \
		POSTGRESQL "Enable PostgreSQL module" off \
		WEBFORM "Enable web form module" off \
		SMTPAUTH "Enable web form module" off

LIB_DEPENDS+=	ssh2:${PORTSDIR}/security/libssh2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--program-transform= --disable-module-ncp

MAN1=		medusa.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not build on ia64
.endif

.if defined(WITH_SVN)
PLIST_SUB+=	SVN=""
LIB_DEPENDS+=	svn_client-1:${PORTSDIR}/devel/subversion \
		apr-1:${PORTSDIR}/devel/apr
CFLAGS+=	-I${LOCALBASE}/include/subversion-1 -I${LOCALBASE}/include/apr-1
.else
PLIST_SUB+=	SVN="@comment "
.endif

.if defined(WITH_POSTGRESQL)
PLIST_SUB+=	POSTGRESQL=""
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--enable-module-postgres
.else
PLIST_SUB+=	POSTGRESQL="@comment "
.endif

.if defined(WITH_WEBFORM)
PLIST_SUB+=	WEBFORM=""
CONFIGURE_ARGS+=	--enable-module-web-form
.else
PLIST_SUB+=	WEBFORM="@comment "
.endif

.if defined(WITH_SMTPAUTH)
PLIST_SUB+=	SMTPAUTH=""
CONFIGURE_ARGS+=	--enable-module-smtp-auth
.else
PLIST_SUB+=	SMTPAUTH="@comment "
.endif

.include <bsd.port.post.mk>
