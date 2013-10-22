# Created by: ijliao
# $FreeBSD$

PORTNAME=	pyzor
PORTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	mail python
MASTER_SITES=	SF

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Collaborative, networked system to detect and block spam

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdbm>=0:${PORTSDIR}/databases/py-gdbm

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PLIST_FILES=	man/man1/pyzor.1.gz \
		man/man1/pyzord.1.gz

post-patch:
	${REINPLACE_CMD} -e '1s,^#!/usr/bin/python,#!/usr/bin/env -S python -Wignore::DeprecationWarning,' \
	${WRKSRC}/scripts/pyzor ${WRKSRC}/scripts/pyzord

post-install:
	${CHMOD} ${SHAREMODE} ${STAGEDIR}${DOCSDIR}/usage.html
	${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/pyzor ${STAGEDIR}${PREFIX}/bin/pyzord
	${INSTALL_MAN} ${WRKSRC}/docs/pyzor.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/pyzord.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
