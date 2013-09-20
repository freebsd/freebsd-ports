# Created by: ijliao
# $FreeBSD$

PORTNAME=	pyzor
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	SF

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	A collaborative, networked system to detect and block spam

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		pyzor.1 pyzord.1

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e '1s,^#!/usr/bin/python,#!/usr/bin/env -S python -Wignore::DeprecationWarning,' \
	${WRKSRC}/scripts/pyzor ${WRKSRC}/scripts/pyzord

post-install:
	${CHMOD} ${SHAREMODE} ${DOCSDIR}/usage.html
	${CHMOD} ${BINMODE} ${PREFIX}/bin/pyzor ${PREFIX}/bin/pyzord
	${INSTALL_MAN} ${WRKSRC}/docs/pyzor.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/pyzord.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
