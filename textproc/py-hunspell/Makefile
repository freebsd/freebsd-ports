# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	0.4.1
CATEGORIES=	textproc devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python module for the Hunspell spellchecker engine

LICENSE=	LGPL3

LIB_DEPENDS=	libhunspell-${HSPLVER}.so:textproc/hunspell

USES=		localbase python
USE_PYTHON=	distutils

HSPLVER=	1.5
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/hunspell.so

pre-configure:
	${REINPLACE_CMD} -e "s|/usr/include|${LOCALBASE}/include|"	\
		-e "s|= \['hunspell|= ['hunspell-${HSPLVER}|"		\
		${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
