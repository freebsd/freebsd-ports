# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	bogofilter
PORTREVISION=	2
CATEGORIES=	mail
PKGNAMESUFFIX=	-tc

DEPRECATED=	TokyoCabinet is being phased out in favor of KyotoCabinet.
EXPIRATION_DATE=2020-12-31

MAINTAINER=	mandree@FreeBSD.org
# Blanket approval for changes by Zach Thompson (address above)

LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

CONFLICTS_INSTALL=	bogofilter-[0-9]* bogofilter-sqlite-[0-9]* bogofilter-kc-[0-9]* bogofilter-lmdb-[0-9]*

CONFIGURE_ARGS=	--with-database=tokyocabinet
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter

.include "${MASTERDIR}/Makefile"
