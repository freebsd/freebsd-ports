# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fonttools
PORTVERSION=	3.44.0
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source library for manipulating fonts, written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python zip
USE_PYTHON=	autoplist concurrent distutils

MAKE_ENV=	FONTTOOLS_MANPATH="man"
NO_ARCH=	yes

SLAVEDIRS=	print/py-fonttools-graphite print/py-fonttools-interpolatable print/py-fonttools-lxml print/py-fonttools-plot print/py-fonttools-symfont print/py-fonttools-ufo print/py-fonttools-unicode print/py-fonttools-woff

OPTIONS_DEFINE=	GRAPHITE INTERPOLATABLE LXML PLOT SYMFONT UFO UNICODE WOFF
GRAPHITE_DESC=	Process graphite type tables in ttLib/tables
INTERPOLATABLE_DESC=	Interpolatability support
LXML_DESC=	Read/write XML files via lxml (faster/safer than built-in ElementTree)
PLOT_DESC=	Visualize DesignSpaceDocument and resulting VariationModel
SYMFONT_DESC=	Symbolic font statistics analysis
UFO_DESC=	Read/write UFO fonts
UNICODE_DESC=	Use latest Unicode Character Database
WOFF_DESC=	Compress/uncompress WOFF webfonts

GRAPHITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools-graphite>=${PORTVERSION}:print/py-fonttools-graphite@${PY_FLAVOR}
INTERPOLATABLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools-interpolatable>=${PORTVERSION}:print/py-fonttools-interpolatable@${PY_FLAVOR}
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools-lxml>=${PORTVERSION}:print/py-fonttools-lxml@${PY_FLAVOR}
PLOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools-plot>=${PORTVERSION}:print/py-fonttools-plot@${PY_FLAVOR}
SYMFONT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools-symfont>=${PORTVERSION}:print/py-fonttools-symfont@${PY_FLAVOR}
UFO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools-ufo>=${PORTVERSION}:print/py-fonttools-ufo@${PY_FLAVOR}
UNICODE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools-unicode>=${PORTVERSION}:print/py-fonttools-unicode@${PY_FLAVOR}
WOFF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools-woff>=${PORTVERSION}:print/py-fonttools-woff@${PY_FLAVOR}

.include <bsd.port.mk>
