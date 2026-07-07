PORTNAME=	bogofilter
PORTREVISION=	1
PKGNAMESUFFIX=	-sqlite

COMMENT?=	Fast, teachable, learning spam detector (SQLite3 database)

DEPRECATED=	# override master port

USES=		sqlite

CONFIGURE_ARGS=	--with-database=sqlite

CONFLICTS_INSTALL=	bogofilter bogofilter-kc bogofilter-lmdb1
MASTERDIR=	${.CURDIR}/../bogofilter
DESCR=		${PKGDIR}/pkg-descr

BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=

.include "${MASTERDIR}/Makefile"
