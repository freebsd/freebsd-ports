# New ports collection makefile for:	pkg_remove
# Version required:	1.0
# Date created:		8 Jan 2000
# Whom:			NAKAJI Hiroyuki <nakaji@tutrp.tut.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	pkg_remove
PKGNAME=	pkg_remove-1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rr.iij4u.or.jp/~sada/scripts/
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
