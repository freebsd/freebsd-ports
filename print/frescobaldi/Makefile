# Created by: martin.dieringer@gmx.de
# $FreeBSD$

PORTNAME=	frescobaldi
DISTVERSIONPREFIX=	v
DISTVERSION=	2.20.0
PORTREVISION=	2
CATEGORIES=	print kde

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Music score editor for lilypond

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poppler-qt4>=0:graphics/py-poppler-qt4 \
		${PYTHON_PKGNAMEPREFIX}python-ly>=0:print/py-python-ly

USES=		gettext kde:4 python:-3.4 desktop-file-utils
USE_GITHUB=	yes
GH_ACCOUNT=	wbsoft
USE_KDE=	kdelibs pykde4_build pykde4_run
USE_PYTHON=	distutils autoplist

INSTALLS_ICONS=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	LILYPOND

LILYPOND_DESC=	Use unstable LilyPond (lilypond-devel)

LILYPOND_RUN_DEPENDS=		lilypond:print/lilypond-devel
LILYPOND_RUN_DEPENDS_OFF=	lilypond:print/lilypond

post-patch:
	@${REINPLACE_CMD} -e 's|'share/man/man1'|'man/man1'|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
