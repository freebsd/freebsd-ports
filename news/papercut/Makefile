# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	papercut
PORTVERSION=	0.9.13
PORTREVISION=	1
CATEGORIES=	news python
MASTER_SITES=	http://pessoal.org/papercut/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Papercut is a news server written in Python, using a MySQL backend

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:databases/py-MySQLdb@${PY_FLAVOR}

USES=		python:2.7 shebangfix
NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_FILES=	*.py auth/*.py storage/*.py

do-configure:
	${CP} ${FILESDIR}/papercut-wrapper ${WRKDIR}/papercut-wrapper
	${REINPLACE_CMD} -e "s,__DATADIR__,${DATADIR}," ${WRKDIR}/papercut-wrapper
	${REINPLACE_CMD} -e "s,__PYTHON__,${PYTHON_CMD}," ${WRKDIR}/papercut-wrapper
	${REINPLACE_CMD} "s,/home/papercut,${DATADIR}," ${WRKSRC}/settings.py

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/cache
	@${MKDIR} ${STAGEDIR}${DATADIR}/logs
.for DIR in auth storage
		@${MKDIR} ${STAGEDIR}${DATADIR}/${DIR}
		${INSTALL_SCRIPT} ${WRKSRC}/${DIR}/* ${STAGEDIR}${DATADIR}/${DIR}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/papercut-wrapper ${STAGEDIR}${PREFIX}/bin/papercut
	${MV} ${STAGEDIR}${DATADIR}/settings.py ${STAGEDIR}${DATADIR}/settings.py.sample

.include <bsd.port.mk>
