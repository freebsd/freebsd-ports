# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	loook
PORTVERSION=	0.6.5
CATEGORIES=	textproc
MASTER_SITES=	http://www.danielnaber.de/loook/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Simple Python tool that search in LibreOffice/OpenOffice files

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_PKGNAMEPREFIX}iniparse>=0:${PORTSDIR}/devel/py-iniparse

WRKSRC=		${WRKDIR}

USES=		zip
USE_PYTHON=	2
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
