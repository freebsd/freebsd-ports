# New ports collection makefile for:    webcopy
# Version required:     0.98b7
# Date created:         14 Sep 1996
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=	webcopy
PKGNAME=	${DISTNAME}-${VERSION}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.inf.utfsm.cl/pub/utfsm/perl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

NO_PACKAGE=	"This program cannot be distributed if modified in any way"
NO_CDROM=	"Don't sell for profit without written permission"
WRKSRC=		${WRKDIR}/${PKGNAME}
VERSION=	0.98b7
ALL_TARGET=

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} webcopy ${PREFIX}/bin
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/webcopy
	cd ${WRKSRC}; ${INSTALL_DATA} webcopy.html ${PREFIX}/share/doc/webcopy

.include <bsd.port.mk>
