# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	misc docs
PKGNAMEPREFIX=	ja-

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Japanese translation of the FreeBSD Documentation Project

BROKEN=		EUC encoding via iconv is broken on 10.X

MASTERDIR=	${.CURDIR}/../freebsd-doc-en
PLIST=		${.CURDIR}/pkg-plist

DOCLANG=	ja_JP.eucJP

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
