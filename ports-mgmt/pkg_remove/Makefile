# New ports collection makefile for:	pkg_remove
# Date created:		8 Jan 2000
# Whom:			NAKAJI Hiroyuki <nakaji@tutrp.tut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	pkg_remove
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	nakaji@jp.freebsd.org
COMMENT=	Utility to uninstall packages

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/pkg_remove
SRC=		${.CURDIR}/src

do-fetch:
	@${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${SRC}/pkg_remove.txt ${PREFIX}/bin/pkg_remove

.include <bsd.port.mk>
