# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-nox11

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	User-level file synchronization tool (without x11 stuff)

CONFLICTS=	unison-[0-9]* unison-devel-[0-9]*

OPTIONS_EXCLUDE=	X11
MASTERDIR=	${.CURDIR}/../unison

.include "${MASTERDIR}/Makefile"
