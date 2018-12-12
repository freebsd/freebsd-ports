# $FreeBSD$

PORTNAME=	lamprop
PORTVERSION=	3.4
PORTREVISION=	2
CATEGORIES=	science python

MAINTAINER=	rsmith@xs4all.nl
COMMENT=	Calculates properties of fiber reinforced composites

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	rsmith-nl
NO_ARCH=	yes

PLIST_FILES=	bin/lamprop \
		man/man1/lamprop.1.gz \
		man/man5/lamprop.5.gz

do-build:
	cd ${WRKSRC} && ${PYTHON_VERSION} build.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lamprop ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/lamprop.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/lamprop.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
