# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	enchant
PORTVERSION=	3.0.1
CATEGORIES=	textproc devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Spellchecking library for Python based on the Enchant library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libenchant.so:textproc/enchant

OPTIONS_DEFINE=	WX
OPTIONS_DEFAULT=WX
WX_DESC=	Provide a wxSpellCheckerDialog
OPTIONS_SUB=	yes
.if ${FLAVOR:Upy36:Mpy3*}
OPTIONS_EXCLUDE=	WX
.endif

USES=		python:3.6+
USE_PYTHON=	distutils py3kplist
NO_ARCH=	yes

WX_USE=		WX=3.0+
WX_VARS=	WX_COMPS=python:run

PLIST_SUB+=	VER=${PORTVERSION}

post-install-WX-off:
	${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/checker/wxSpellCheckerDialog*

.include <bsd.port.mk>
