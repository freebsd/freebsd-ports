# New ports collection makefile for:	bogofilter-tc
# Date created:				2008-08-29
# Whom:				   	Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	bogofilter
PORTREVISION=	4
CATEGORIES=	mail
PKGNAMESUFFIX=	-tc

MAINTAINER=	matthias.andree@gmx.de
# Blanket approval for changes by Zach Thompson (address above)

LIB_DEPENDS=	tokyocabinet.8:${PORTSDIR}/databases/tokyocabinet

CONFLICTS=	bogofilter-[0-9]* [a-z][a-z]-bogofilter-[1-9]* bogofilter-sqlite-[0-9]* bogofilter-qdbm-[0-9]*

CONFIGURE_ARGS=	--with-database=tokyocabinet
BF_CPPFLAGS=	-I${LOCALBASE}/include
BF_LIBS=
DESCR=		${PKGDIR}/pkg-descr

MASTERDIR=	${.CURDIR}/../bogofilter

.include "${MASTERDIR}/Makefile"
