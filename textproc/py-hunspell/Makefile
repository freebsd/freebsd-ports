PORTNAME=	hunspell
PORTVERSION=	0.5.5
PORTREVISION=	1
CATEGORIES=	textproc devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python module for the Hunspell spellchecker engine
WWW=		https://pypi.org/project/hunspell/

LICENSE=	LGPL3

LIB_DEPENDS=	libhunspell-${HSPLVER}.so:textproc/hunspell

USES=		python
USES+=		localbase
USE_PYTHON=	distutils

HSPLVER=	1.7
PLIST_FILES=	${PYTHON_SITELIBDIR}/hunspell${PYTHON_EXT_SUFFIX}.so

pre-configure:
	${REINPLACE_CMD} -e "s|/usr/include|${LOCALBASE}/include|"	\
		-e "s|= \['hunspell|= ['hunspell-${HSPLVER}|"		\
		${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
