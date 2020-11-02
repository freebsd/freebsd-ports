# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	imerge
PORTVERSION=	0.2.4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.iDaemons.org/pub/distfiles/ \
		LOCAL/knu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to help merge one file to another interactively

USES=		tar:bzip2 uidfix

MAKE_ARGS=	PREFIX="${PREFIX}" MANPREFIX="${MANPREFIX}"
MAKEFILE=	BSDmakefile

PLIST_FILES=	bin/imerge \
		man/man1/imerge.1.gz

.include <bsd.port.mk>
