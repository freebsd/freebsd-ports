# Ports collection Makefile for:	HTMLgen
# Date created:				03/20/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	HTMLgen
PORTVERSION=	2.2.2
CATEGORIES=	www python
MASTER_SITES=	http://starship.python.net/crew/friedrich/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	HTMLgen

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python library for the generation of HTML documents

USE_PYTHON=	yes
NO_BUILD=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${TAR} -C ${WRKSRC} -cf - README html image | \
		${TAR} -C ${DOCSDIR} -xvf -
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${DOCSDIR}
	@${FIND} ${DOCSDIR} -type d -exec ${CHMOD} 0555 {} \;
	@${FIND} ${DOCSDIR} -type f -exec ${CHMOD} 0444 {} \;
.endif

.include <bsd.port.mk>
