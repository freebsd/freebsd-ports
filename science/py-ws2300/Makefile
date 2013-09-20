# Created by: Stefan Bethke <stb@lassitu.de>
# $FreeBSD$

PORTNAME=	ws2300
PORTVERSION=	1.7
CATEGORIES=	science python
MASTER_SITES=	http://ace-host.stuart.id.au/russell/files/ws2300/ \
		http://www.transit.hanse.de/mirror/ace-host.stuart.id.au/russell/files/ws2300/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	stb@lassitu.de
COMMENT=	Driver for the LaCrosse WS-2300 weather station

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=	ws2300.1

NO_STAGE=	yes
post-install:
	#@${LN} -sf ${PYTHONPREFIX_SITELIBDIR}/ws2300.py ${PREFIX}/bin/ws2300
	@${INSTALL_SCRIPT} ${FILESDIR}/ws2300 ${PREFIX}/bin/ws2300
	@${INSTALL_MAN} ${WRKSRC}/ws2300.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
