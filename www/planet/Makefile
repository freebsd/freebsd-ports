# Created by: Alan Snelson <alan@wave2.co.uk>
# $FreeBSD$

PORTNAME=	planet
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	http://www.planetplanet.org/download/

MAINTAINER=	alan@wave2.co.uk
COMMENT=	Planet is a flexible feed aggregator - and more!

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/Tidy/Tidy.py:${PORTSDIR}/devel/py-mx-experimental \
		${PYTHON_PKGNAMEPREFIX}bsddb>0:${PORTSDIR}/databases/py-bsddb

USES=		tar:bzip2
NO_BUILD=	yes
USE_PYTHON=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	@${RM}	${WRKSRC}/.bzrignore
	@${FIND} ${WRKSRC}/ -type d -name '.bzr' | ${XARGS} ${RM} -rf

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
