# New ports collection makefile for:	urweb
# Date created:		4 Apr 2012
# Whom:			Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$

PORTNAME=	urweb
PORTVERSION=	20120329
PORTREVISION=	1
CATEGORIES=	lang www
MASTER_SITES=	http://www.impredicative.com/ur/
EXTRACT_SUFX=	.tgz

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Ultimate host for embedded domain-specific languages

LICENSE=	BSD
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE

BUILD_DEPENDS=	mlton:${PORTSDIR}/lang/mlton

CONFIGURE_ENV=	CCARGS="-I${LOCALBASE}/include"

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
ONLY_FOR_ARCHS=	i386 amd64

OPTIONS=	ELISP "Install contributed Emacs Lisp" on \
		PGSQL "Enable PostgreSQL Support" on \
		SQLITE "Enable Sqlite Support" off \
		MYSQL "Enable Mysql Support" off

.include <bsd.port.options.mk>

.ifdef (WITH_ELISP)
PLIST_SUB+=	ELISP=""
CONFIGURE_ARGS+=	with_emacs=yes
.else
PLIST_SUB+=	ELISP="@comment "
CONFIGURE_ARGS+=	with_emacs=no
.endif

.ifdef (WITH_PGSQL)
USE_PGSQL=	server
.else
CONFIGURE_ENV+=	PGHEADER="no"
.endif

.ifdef (WITH_SQLITE)
USE_SQLITE=	yes
.else
CONFIGURE_ENV+=	SQHEADER="no"
.endif

.ifdef (WITH_MYSQL)
USE_MYSQL=	yes
.else
CONFIGURE_ENV+=	MSHEADER="no"
.endif

.include <bsd.port.mk>
