# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gato
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Gato-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python-based toolbox to visualise algorithms on graphs

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LGPL.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${FLAVOR}

NO_ARCH=	yes
PORTEXAMPLES=	*
USES=		python:2.7
USE_PYTHON=	autoplist distutils

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for sample in *.alg *.pro *.cat
	${INSTALL_DATA} ${WRKSRC}/${sample} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
