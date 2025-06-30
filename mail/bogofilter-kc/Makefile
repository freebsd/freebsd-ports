PORTNAME=	bogofilter
PORTREVISION=	0
CATEGORIES=	mail
PKGNAMESUFFIX=	-kc

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Fast, teachable, learning spam detector (KyotoCabinet database)

LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

CONFLICTS_INSTALL=	bogofilter bogofilter-bdb bogofilter-sqlite  # bogofilter-bdb is historic, but let's keep this for a while

CONFIGURE_ARGS=	--with-database=kyotocabinet
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter

.include "${MASTERDIR}/Makefile"
