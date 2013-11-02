# Created by: Tim Daneliuk <tsshbatch@tundraware.com>
# $FreeBSD$

PORTNAME=	tsshbatch
PORTVERSION=	1.171
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

PLIST_FILES=	bin/tsshbatch.py \
		man/man1/tsshbatch.1.gz
PORTDOCS=	WHATSNEW.txt \
		tsshbatch.html \
		tsshbatch.pdf \
		tsshbatch.ps \
		tsshbatch.rst

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tsshbatch.py ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tsshbatch.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	cd ${WRKSRC} && ${INSTALL_DATA} $i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
