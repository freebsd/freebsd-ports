# New ports collection makefile for:	convertall
# Date created:		2004-08-12
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	convertall
PORTVERSION=	0.3.1
CATEGORIES=	math
MASTER_SITES=	http://bellz.org/convertall/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another unit converter

BUILD_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt
RUN_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt

WRKSRC=		${WRKDIR}/ConvertAll
USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
PORTDOCS=	README.html INSTALL LICENSE

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|doc||' ${WRKSRC}/install.py
.endif

do-install:
	(cd ${WRKSRC};${PYTHON_CMD} ${WRKSRC}/install.py -p ${PREFIX})

.include <bsd.port.mk>
