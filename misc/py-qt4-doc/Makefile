# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	doc
PORTVERSION=	${PYQT4_VERSION}
PORTEPOCH=	1
CATEGORIES=	misc devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, documentation

DISTINFO_FILE=	${PYQT4_DISTINFO_FILE}
NO_BUILD=	yes

USES=		python pyqt:4
USE_PYQT=	#
USE_PYTHON=	flavors

DOCSDIR=	${PREFIX}/share/doc/py-qt4

do-install:
	cd ${WRKSRC} &&\
		${MKDIR} ${STAGEDIR}${DOCSDIR} &&\
		${INSTALL_DATA} LICENSE \
				NEWS \
				README \
				THANKS\
			${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
