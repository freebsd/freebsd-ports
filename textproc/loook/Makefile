# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	loook
PORTVERSION=	0.6.5
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.danielnaber.de/loook/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	python

MAINTAINER=	koalative@gmail.com
COMMENT=	Simple Python tool that search in LibreOffice/OpenOffice files

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR}

WRKSRC=		${WRKDIR}

USES=		python:2.7 zip
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/${PORTNAME}.py
	@(cd ${WRKSRC} ; ${RM} *.py.bak)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
