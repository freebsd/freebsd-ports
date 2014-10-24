# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cjc
PORTVERSION=	1.2.1
CATEGORIES=	net-im python
MASTER_SITES=	GHC

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console Jabber Client

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyxmpp>=0:${PORTSDIR}/net-im/py-pyxmpp

USE_GITHUB=	yes
GH_ACCOUNT=	Jajcus

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		python:2 shebangfix
SHEBANG_FILES=	cjc.in cjc.py cjc/main.py

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	ChangeLog README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	manual.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|prefix=.*|prefix=${PREFIX}|; \
		 s|$$(INSTALL_DIR) $$(DESTDIR)$$(pkg_docdir)||; \
		 s|$$(INSTALL_DATA) $$(DOCS) $$(DESTDIR)$$(pkg_docdir)||; \
		 s|INSTALL=.*|INSTALL=${INSTALL}|; \
		 s|INSTALL_DATA=.*|INSTALL_DATA=${INSTALL_DATA}|; \
		 s|^INSTALL_DIR=.*|INSTALL_DIR=${MKDIR}|; \
		 /compileall/d' ${WRKSRC}/Makefile

post-install:
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f ${DATADIR_REL})

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
