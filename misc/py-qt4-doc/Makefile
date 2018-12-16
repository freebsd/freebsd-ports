# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	doc
PORTVERSION=	${PYQT4_VERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	misc devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, documentation

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

DISTINFO_FILE=	${PYQT4_DISTINFO_FILE}
NO_BUILD=	yes

USES=		python pyqt:4
USE_PYQT=	#
USE_PYTHON=	concurrent flavors py3kplist

do-install:
	cd ${WRKSRC} &&\
		${MKDIR} ${STAGEDIR}${PYQT_DOCDIR} &&\
		${INSTALL_DATA} LICENSE \
				NEWS \
				README \
				THANKS\
			${STAGEDIR}${PYQT_DOCDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${PYQT_DOCDIR}

.include <bsd.port.mk>
