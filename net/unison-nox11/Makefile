# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-nox11

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	User-level file synchronization tool (without x11 stuff)

CONFLICTS=	unison-[0-9]* unison-devel-[0-9]*

OPTIONS_EXCLUDE=	X11
OPTIONS_DEFAULT=	DOCS
MASTERDIR=	${.CURDIR}/../unison

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
