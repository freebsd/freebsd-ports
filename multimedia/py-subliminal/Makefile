# Created by: William Grzybowski <william88@gmail.com>
# $FreeBSD$

PORTNAME=	subliminal
PORTVERSION=	0.7.2
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python library to search and download subtitles

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bs4/__init__.py:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}enzyme>=0.4.0:${PORTSDIR}/multimedia/py-enzyme \
		${PYTHON_PKGNAMEPREFIX}guessit>=0.6.1:${PORTSDIR}/multimedia/py-guessit \
		${PYTHON_PKGNAMEPREFIX}requests>=1.1:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:${PORTSDIR}/www/py-html5lib \
		${PYTHON_PKGNAMEPREFIX}charade>0:${PORTSDIR}/textproc/py-charade \
		${PYTHON_PKGNAMEPREFIX}pysrt>0:${PORTSDIR}/textproc/py-pysrt \
		${PYTHON_PKGNAMEPREFIX}babelfish>=0.3.0:${PORTSDIR}/devel/py-babelfish \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>0:${PORTSDIR}/devel/py-dogpile.cache

USE_PYTHON=	2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes

post-patch:
	@${REINPLACE_CMD} "s/.com',/.com', zip_safe=False,/" \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} \
		-e 's,^requests.*,requests,g' \
		${WRKSRC}/requirements.txt

.include <bsd.port.mk>
