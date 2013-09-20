# Created by: Tim Daneliuk <tsshbatch@tundraware.com>
# $FreeBSD$

PORTNAME=	tsshbatch
PORTVERSION=	1.137
CATEGORIES=	security python
MASTER_SITES=	http://www.tundraware.com/Software/tsshbatch/

MAINTAINER=	tsshbatch@tundraware.com
COMMENT=	Batch ssh Operations

LICENSE=	tsshbatch
LICENSE_NAME=	tsshbatch
LICENSE_FILE=	${WRKSRC}/tsshbatch-license.txt
LICENSE_PERMS=	auto-accept

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.7.7.1:${PORTSDIR}/security/py-paramiko

USE_PYTHON_RUN=	yes

MAN1=	tsshbatch.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/tsshbatch.py
PORTDOCS=	WHATSNEW.txt \
		tsshbatch.html \
		tsshbatch.pdf \
		tsshbatch.ps \
		tsshbatch.rst

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tsshbatch.py ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tsshbatch.1.gz ${MAN1PREFIX}/man/man1

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	cd ${WRKSRC} && ${INSTALL_DATA} $i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
