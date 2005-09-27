# New ports collection makefile for:	planet
# Date created:				26 September 2005
# Whom:					Alan Snelson <alan@wave2.co.uk>
#
# $FreeBSD$
#

PORTNAME=	planet
PORTVERSION=	0.0p22
CATEGORIES=	www
MASTER_SITES=	http://www.wave2.co.uk/freebsd/planet/

MAINTAINER=	alan@wave2.co.uk
COMMENT=	Planet is a flexible feed aggregator - and more!

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/Tidy/Tidy.py:${PORTSDIR}/devel/py-mx-experimental

NO_BUILD=	yes
USE_PYTHON=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${PREFIX}/share/planet
	${CP} -R ${WRKSRC}/ ${PREFIX}/share/planet

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
