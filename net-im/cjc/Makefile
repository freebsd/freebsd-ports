# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cjc
PORTVERSION=	1.2.1
CATEGORIES=	net-im python
MASTER_SITES=	GHC

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console Jabber Client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyxmpp>=0:net-im/py-pyxmpp@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	Jajcus

USES=		python:2 shebangfix
SHEBANG_FILES=	cjc.in cjc.py cjc/main.py
NO_ARCH=	yes

PORTDOCS=	*

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README \
		${WRKSRC}/doc/manual.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
