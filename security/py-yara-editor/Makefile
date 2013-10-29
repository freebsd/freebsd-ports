# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	yara-editor
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Editor for yara rules

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=0:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_PKGNAMEPREFIX}yara>=0:${PORTSDIR}/security/py-yara

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	README

post-patch:
	${REINPLACE_CMD} -e '/config_dir/d' \
		-e '/en\/man8/d' \
		-e "/'man8'/s/fr/en/" ${WRKSRC}/setup.py

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
