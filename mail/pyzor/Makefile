# Created by: ijliao
# $FreeBSD$

PORTNAME=	pyzor
PORTVERSION=	0.5.0
PORTREVISION=	5
CATEGORIES=	mail python
MASTER_SITES=	SF

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Collaborative, networked system to detect and block spam

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdbm>=0:${PORTSDIR}/databases/py-gdbm

USES=		python tar:bzip2
USE_PYTHON=	distutils autoplist

PLIST_FILES=	man/man1/pyzor.1.gz \
		man/man1/pyzord.1.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e '1s,^#!/usr/bin/python,#!/usr/bin/env -S python -Wignore::DeprecationWarning,' \
	${WRKSRC}/scripts/pyzor ${WRKSRC}/scripts/pyzord
.if ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|share/doc/pyzor|${DOCSDIR}|' ${WRKSRC}/setup.py
.else
	${REINPLACE_CMD} -e '/usage.html/d' ${WRKSRC}/setup.py
.endif

post-install:
	${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/pyzor ${STAGEDIR}${PREFIX}/bin/pyzord
	${INSTALL_MAN} ${WRKSRC}/docs/pyzor.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/pyzord.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${CHMOD} ${SHAREMODE} ${STAGEDIR}${DOCSDIR}/usage.html
.endif

.include <bsd.port.mk>
