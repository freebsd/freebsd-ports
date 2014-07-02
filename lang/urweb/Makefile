# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	urweb
PORTVERSION=	20120925
PORTREVISION=	1
CATEGORIES=	lang www
MASTER_SITES=	http://www.impredicative.com/ur/
EXTRACT_SUFX=	.tgz

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Ultimate host for embedded domain-specific languages

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	mlton:${PORTSDIR}/lang/mlton

CONFIGURE_ENV=	CCARGS="-I${LOCALBASE}/include"

GNU_CONFIGURE=	yes
USES=		gmake libtool
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
