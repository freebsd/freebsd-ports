# New ports collection makefile for:	pkg_remove
# Date created:		8 Jan 2000
# Whom:			NAKAJI Hiroyuki <nakaji@tutrp.tut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	pkg_remove
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rr.iij4u.or.jp/~sada/scripts/
DISTNAME=	pkg_remove
EXTRACT_SUFX=	.txt

MAINTAINER=	nakaji@tutrp.tut.ac.jp

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pkg_remove.txt ${PREFIX}/bin/pkg_remove

.include <bsd.port.mk>
