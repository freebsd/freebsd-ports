# New ports collection makefile for: qsf
# Date created:		15 January 2004
# Whom:			liamfoy@sepulcrum.org
#
# $FreeBSD$
#

PORTNAME=	qsf
PORTVERSION=	1.2.7
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	jack@jarasoft.net
COMMENT=	A small fast spam filter intended to be used with procmail

OPTIONS=	GDBM "GDBM support" off \
		MYSQL "MySQL support" off \
		SQLITE2 "SQLite2 support" off

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		qsf.1
PLIST_FILES=	bin/qsf

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_GDBM)
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm
.else
CONFIGURE_ARGS+=	--without-gdbm
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_SQLITE2)
USE_SQLITE=	2
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|Linux|@VERSION@|g' ${WRKSRC}/doc/quickref.1.in

.include <bsd.port.post.mk>
