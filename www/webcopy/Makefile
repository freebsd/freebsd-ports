# New ports collection makefile for:    webcopy
# Date created:         14 Sep 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	webcopy
PORTVERSION=	0.98b7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	steve

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Web Mirroring Program

NO_PACKAGE=	"This program cannot be distributed if modified in any way"
NO_CDROM=	"Don't sell for profit without written permission"
ALL_TARGET=

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} webcopy ${PREFIX}/bin
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/webcopy
	cd ${WRKSRC}; ${INSTALL_DATA} webcopy.html ${PREFIX}/share/doc/webcopy

.include <bsd.port.mk>
