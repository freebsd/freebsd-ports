# Created by: Tim Daneliuk <tsshbatch@tundraware.com>
# $FreeBSD$

PORTNAME=	tsshbatch
PORTVERSION=	1.317
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://www.tundraware.com/Software/tsshbatch/

MAINTAINER=	tsshbatch@tundraware.com
COMMENT=	Batch SSH operations

LICENSE=	TundraWare
LICENSE_NAME=	TundraWare license
LICENSE_FILE=	${WRKSRC}/tsshbatch-license.txt
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell no-auto-accept

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.7.7.1:security/py-paramiko@${PY_FLAVOR}

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	tsshbatch.py
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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
