# New ports collection makefile for:	urweb
# Date created:		4 Apr 2012
# Whom:			Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$

PORTNAME=	urweb
PORTVERSION=	20120807
CATEGORIES=	lang www
MASTER_SITES=	http://www.impredicative.com/ur/
EXTRACT_SUFX=	.tgz

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Ultimate host for embedded domain-specific languages

LICENSE=	BSD

BUILD_DEPENDS=	mlton:${PORTSDIR}/lang/mlton

CONFIGURE_ENV=	CCARGS="-I${LOCALBASE}/include"

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	ELISP PGSQL SQLITE MYSQL
OPTIONS_DEFAULT=ELISP PGSQL
OPTIONS_EXCLUDE=NLS DOCS
ELISP_DESC=	Install contributed Emacs Lisp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MELISP}
PLIST_SUB+=	ELISP=""
CONFIGURE_ARGS+=	with_emacs=yes
.else
PLIST_SUB+=	ELISP="@comment "
CONFIGURE_ARGS+=	with_emacs=no
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	server
.else
CONFIGURE_ENV+=	PGHEADER="no"
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
.else
CONFIGURE_ENV+=	SQHEADER="no"
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.else
CONFIGURE_ENV+=	MSHEADER="no"
.endif

.include <bsd.port.mk>
