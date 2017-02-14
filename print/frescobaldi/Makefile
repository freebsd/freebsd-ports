# Created by: martin.dieringer@gmx.de
# $FreeBSD$

PORTNAME=	frescobaldi
PORTVERSION=	2.19.0
DISTVERSIONPREFIX=	v
CATEGORIES=	print kde

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Music score editor for lilypond

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	lilypond:print/lilypond \
		${PYTHON_PKGNAMEPREFIX}poppler-qt4>=0:graphics/py-poppler-qt4 \
		${PYTHON_PKGNAMEPREFIX}python-ly>=0:print/py-python-ly

USE_GITHUB=	yes
GH_ACCOUNT=	wbsoft

USES=		gettext kde:4 python
INSTALLS_ICONS=	yes
USE_KDE=	kdelibs pykde4_build pykde4_run
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
