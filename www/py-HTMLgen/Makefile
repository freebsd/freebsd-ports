# Ports collection Makefile for:	HTMLgen
# Date created:				03/20/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		py-HTMLgen
PORTVERSION=		2.1
CATEGORIES=		www python
MASTER_SITES=		ftp://ftp.python.org/pub/python/contrib-09-Dec-1999/Network/
DISTNAME=		HTMLgen

MAINTAINER=		nectar@FreeBSD.org

USE_PYTHON=		yes

WRKSRC=			${WRKDIR}/HTMLgen
PLIST=			${WRKDIR}/PLIST

DOCDIR=			${PREFIX}/share/doc/HTMLgen
FIND?=			find

pre-install:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGDIR}/pkg-plist.docs >> ${PLIST}
	@${MKDIR} ${PREFIX}/share/doc/HTMLgen
	@${TAR} -C ${WRKSRC} -cf - README html image | \
		${TAR} -C ${DOCDIR} -xvf -
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${DOCDIR}
	@${FIND} ${DOCDIR} -type d -exec ${CHMOD} 0555 {} \;
	@${FIND} ${DOCDIR} -type f -exec ${CHMOD} 0444 {} \;
.endif

.include <bsd.port.mk>
