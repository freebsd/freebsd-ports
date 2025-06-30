PORTNAME=	bogofilter
PORTREVISION=	0
CATEGORIES=	mail
PKGNAMESUFFIX=	-sqlite

MAINTAINER=	mandree@FreeBSD.org
COMMENT?=	Fast, teachable, learning spam detector (SQLite3 database)

USES=		sqlite
CONFLICTS_INSTALL=	bogofilter bogofilter-bdb bogofilter-kc  # bogofilter-bdb is historic, but let's keep this for a while

CONFIGURE_ARGS=	--with-database=sqlite
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter

.include "${MASTERDIR}/Makefile"
