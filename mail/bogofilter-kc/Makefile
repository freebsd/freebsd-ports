PORTNAME=	bogofilter
PORTREVISION=	1
PKGNAMESUFFIX=	-kc

COMMENT=	Fast, teachable, learning spam detector (KyotoCabinet database)

DEPRECATED=	# override master port

LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

CONFIGURE_ARGS=	--with-database=kyotocabinet

CONFLICTS_INSTALL=	bogofilter bogofilter-lmdb1 bogofilter-sqlite

MASTERDIR=	${.CURDIR}/../bogofilter
DESCR=		${PKGDIR}/pkg-descr

BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=

.include "${MASTERDIR}/Makefile"
