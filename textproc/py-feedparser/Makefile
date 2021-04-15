# Created by: ijliao

PORTNAME=	feedparser
PORTVERSION=	6.0.2
PORTREVISION=	1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Universal feed parser written in Python

LICENSE=	BSD2CLAUSE PSFL
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+ tar:bzip2
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

GH_ACCOUNT=	kurtmckee

NO_ARCH=	yes

PORTDOCS=	NEWS README.rst

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 3700
PLIST_FILES+=	${PYTHON_SITELIBDIR}/sgmllib.py

post-install:
	${INSTALL_DATA} ${FILESDIR}/sgmllib.py ${STAGEDIR}/${PYTHON_SITELIBDIR}/sgmllib.py
.endif

post-patch:
	@${REINPLACE_CMD} '/sgmllib3k/d' ${WRKSRC}/setup.py

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test:
	@(cd ${WRKSRC}; ${PYTHON_CMD} tests/runtests.py)

.include <bsd.port.post.mk>
