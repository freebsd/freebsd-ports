# New ports collection makefile for:	papercut
# Date created:				2003-07-01
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	papercut
PORTVERSION=	0.9.13
CATEGORIES=	news python
MASTER_SITES=	http://pessoal.org/papercut/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Papercut is a news server written in Python, using a MySQL backend

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/MySQLdb/__init__.py:${PORTSDIR}/databases/py-MySQLdb

USE_PYTHON=	yes
NO_BUILD=	yes

do-configure:
	@${CP} ${FILESDIR}/papercut-wrapper ${WRKDIR}/papercut-wrapper
	@${REINPLACE_CMD} -e "s,__DATADIR__,${DATADIR}," ${WRKDIR}/papercut-wrapper
	@${REINPLACE_CMD} -e "s,__PYTHON__,${PYTHON_CMD}," ${WRKDIR}/papercut-wrapper
	@${REINPLACE_CMD} "s,/home/papercut,${DATADIR}," ${WRKSRC}/settings.py

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@${MKDIR} ${DATADIR}/cache
	@${MKDIR} ${DATADIR}/logs
.for DIR in auth storage
		@${MKDIR} ${DATADIR}/${DIR}
		@${INSTALL_SCRIPT} ${WRKSRC}/${DIR}/* ${DATADIR}/${DIR}
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/papercut-wrapper ${PREFIX}/bin/papercut
	@${MV} ${DATADIR}/settings.py ${DATADIR}/settings.py.sample

post-install:
	@${ECHO_MSG} "To use papercut you need to copy ${DATADIR}/settings.py.sample"
	@${ECHO_MSG} "to ${DATADIR}/settings.py and edit it."

.include <bsd.port.mk>
