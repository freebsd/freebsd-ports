# Ports collection Makefile for:	HTMLgen
# Version required:			2.1
# Date created:				03/20/1999
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.4 1998/11/14 09:43:26 asami Exp $
#

DISTNAME=		HTMLgen
PKGNAME=		py-HTMLgen-2.1
CATEGORIES=		www
MASTER_SITES=		http://starship.skyport.net/crew/friedrich/ \
			http://www.nectar.com/distfiles/

MAINTAINER=		nectar@FreeBSD.ORG

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		python:${PORTSDIR}/lang/python

WRKSRC=			${WRKDIR}/HTMLgen
PLIST=			${WRKDIR}/PLIST

DOCDIR=			${PREFIX}/share/doc/HTMLgen
CHMOD?=			chmod
CHOWN?=			chown
FIND?=			find

pre-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST}
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGDIR}/PLIST.docs >> ${PLIST}
	@${MKDIR} ${PREFIX}/share/doc/HTMLgen
	@${TAR} -C ${WRKSRC} -cf - README html image | \
		${TAR} -C ${DOCDIR} -xvf -
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${DOCDIR}
	@${FIND} ${DOCDIR} -type d -exec ${CHMOD} 0555 {} \;
	@${FIND} ${DOCDIR} -type f -exec ${CHMOD} 0444 {} \;
.endif

.include <bsd.port.mk>
