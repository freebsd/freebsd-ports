# New ports collection makefile for:   wmmon
# Version required:    1.0b2
# Date created:        27 November 1998
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $Id$
#

DISTNAME=	wmmon-1.0b2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.mezaway.org/pub/
DISTFILES=	wmmon-1.0b2.tar.gz wmmon-1.0b2-bsd.tar.gz

MAINTAINER=	kkennawa@physics.adelaide.edu.au

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=   yes

WRKSRC=		${WRKDIR}/wmmon.app/wmmon

pre-patch:
	cd ${WRKDIR}/wmmon.app && ${PATCH} -p < ${WRKDIR}/wmmon-freebsd.patch

post-extract:
	${CP} ${WRKDIR}/wmmon/Makefile.FreeBSD ${WRKSRC}/Makefile

pre-clean:
	${RM} ${WRKDIR}/wmmon-freebsd.patch
	${RM} -rf ${WRKDIR}/wmmon

post-install:
	strip ${PREFIX}/bin/wmmon

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/wmmon
	${INSTALL_MAN} ${WRKSRC}/../HINTS ${PREFIX}/share/doc/wmmon
.endif

.include <bsd.port.mk>
