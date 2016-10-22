# Created by: Tim Daneliuk <tsshbatch@tundraware.com>
# $FreeBSD$

PORTNAME=	tsshbatch
PORTVERSION=	1.317
CATEGORIES=	security python
MASTER_SITES=	http://www.tundraware.com/Software/tsshbatch/

MAINTAINER=	tsshbatch@tundraware.com
COMMENT=	Batch SSH operations

LICENSE=	tsshbatch
LICENSE_NAME=	tsshbatch
LICENSE_FILE=	${WRKSRC}/tsshbatch-license.txt
LICENSE_PERMS=	auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.7.7.1:security/py-paramiko

USES=		python:run
NO_ARCH=	yes

PLIST_FILES=	bin/tsshbatch.py \
		man/man1/tsshbatch.1.gz
PORTDOCS=	WHATSNEW.txt \
		tsshbatch.html \
		tsshbatch.pdf \
		tsshbatch.ps \
		tsshbatch.rst

OPTIONS_DEFINE=	DOCS

do-install:
	cp -p ${WRKSRC}/Docs/* ${WRKSRC}/
	${INSTALL_SCRIPT} ${WRKSRC}/tsshbatch.py ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tsshbatch.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
