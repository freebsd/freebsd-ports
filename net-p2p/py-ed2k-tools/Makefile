PORTNAME=	ed2k-tools
PORTVERSION=	0.1
CATEGORIES=	net-p2p python
MASTER_SITES=	SF/${PORTNAME}/ed2k-python/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ed2k_python-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Python framework for manipulating eD2K metafiles
WWW=		https://ed2k-tools.sourceforge.net/python.shtml

LICENSE=	MIT

USES=		python:run shebangfix
SHEBANG_FILES=	fix_sofar.py make_met.py non-met/shutdown_core.py \
		retrieve_link.py temp_summary.py
WRKSRC=		${WRKDIR}/ed2k_python

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${PYTHON_SITELIBDIR}/ed2k_metutils.py \
		${SHEBANG_FILES:T:S,^,bin/,}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/ed2k_metutils.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${SHEBANG_FILES:S,^,${WRKSRC}/,} \
		${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
