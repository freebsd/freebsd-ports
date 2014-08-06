# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	HTMLgen
PORTVERSION=	2.2.2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/ \
		http://starship.python.net/crew/friedrich/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	HTMLgen

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for the generation of HTML documents

USE_PYTHON=	2
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|python |${PYTHON_CMD} |' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${TAR} -C ${WRKSRC} -cf - README html image | \
		${TAR} -C ${STAGEDIR}${DOCSDIR} -xvf -
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${STAGEDIR}${DOCSDIR}
	@${FIND} ${STAGEDIR}${DOCSDIR} -type d -exec ${CHMOD} 0555 {} \;
	@${FIND} ${STAGEDIR}${DOCSDIR} -type f -exec ${CHMOD} 0444 {} \;

.include <bsd.port.mk>
