# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	python-registry
PORTVERSION=	0.2.5
CATEGORIES=	security devel python
MASTER_SITES=	GH
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Read access to Windows Registry files

LICENSE=	AL2

USE_GITHUB=	yes
GH_ACCOUNT=	williballenthin
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	8ea7e05

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|0.2.4.1|${PORTVERSION}|' ${WRKSRC}/Registry/__init__.py
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/samples/*

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${WRKSRC}/documentation/* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/samples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
