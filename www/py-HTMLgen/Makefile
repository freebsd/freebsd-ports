# Ports collection Makefile for:	HTMLgen
# Date created:				03/20/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		py-HTMLgen
PORTVERSION=		2.2.2
CATEGORIES=		www python
MASTER_SITES=		http://starship.python.net/crew/friedrich/
DISTNAME=		HTMLgen

MAINTAINER=		ports@FreeBSD.org

USE_PYTHON=		yes

WRKSRC=			${WRKDIR}/HTMLgen

DOCDIR=			${PREFIX}/share/doc/HTMLgen

pre-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/HTMLgen
	@${TAR} -C ${WRKSRC} -cf - README html image | \
		${TAR} -C ${DOCDIR} -xvf -
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${DOCDIR}
	@${FIND} ${DOCDIR} -type d -exec ${CHMOD} 0555 {} \;
	@${FIND} ${DOCDIR} -type f -exec ${CHMOD} 0444 {} \;
.endif

.include <bsd.port.mk>
