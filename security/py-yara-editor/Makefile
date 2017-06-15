# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	yara-editor
PORTVERSION=	0.1.5
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Editor for yara rules

LICENSE=	GPLv3

BROKEN=		Unfetchable (google code has gone away)
DEPRECATED=	Unfetchable for more than six months (google code has gone away)
EXPIRATION_DATE=	2017-04-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yara>=0:security/py-yara

USES=		pyqt:4 python:2
USE_PYQT=	core_run gui_run
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	README

post-patch:
	${REINPLACE_CMD} -e '/config_dir/d' \
		-e '/en\/man8/d' \
		-e "/'man8'/s/fr/en/" ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
