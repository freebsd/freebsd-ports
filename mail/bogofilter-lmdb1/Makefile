PORTNAME=	bogofilter
PORTREVISION=	0
PKGNAMESUFFIX=	-lmdb1

COMMENT=	Fast, teachable, learning spam detector (LMDB 1.0 database)

DEPRECATED=	This port will be renamed to bogofilter at some point, see UPDATING
# at the same time, bogofilter shall update from lmdb0 to lmdb (1.0)
EXPIRATION_DATE=2026-12-31

LIB_DEPENDS=	liblmdb.so.1:databases/lmdb

CONFIGURE_ARGS=	--with-database=lmdb

CONFLICTS_INSTALL=	bogofilter bogofilter-kc bogofilter-sqlite

MASTERDIR=	${.CURDIR}/../bogofilter
DESCR=		${PKGDIR}/pkg-descr

BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=

.include "${MASTERDIR}/Makefile"
