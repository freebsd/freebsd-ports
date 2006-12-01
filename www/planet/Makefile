# New ports collection makefile for:    planet
# Date created:                         26 September 2005
# Whom:                                 Alan Snelson <alan@wave2.co.uk>
#
# $FreeBSD$
#

PORTNAME=	planet
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	http://www.planetplanet.org/download/

MAINTAINER=	alan@wave2.co.uk
COMMENT=	Planet is a flexible feed aggregator - and more!

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/Tidy/Tidy.py:${PORTSDIR}/devel/py-mx-experimental \
		${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb

USE_BZIP2=	yes
NO_BUILD=	yes
USE_PYTHON=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	@${RM}	${WRKSRC}/.bzrignore
	@${FIND} ${WRKSRC}/ -type d -name '.bzr' | ${XARGS} ${RM} -rf

do-install:
	${MKDIR} ${PREFIX}/share/planet
	${CP} -R ${WRKSRC}/ ${PREFIX}/share/planet

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
