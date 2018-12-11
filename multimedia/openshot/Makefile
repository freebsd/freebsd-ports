# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	openshot
PORTVERSION=	1.4.3
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	http://launchpad.net/openshot/${PORTVERSION:C/\.[0-9]+$//}/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Non-linear video editor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		frei0r-plugins>=0:graphics/frei0r-plugins \
		${PYTHON_PKGNAMEPREFIX}goocanvas>=0:graphics/py-goocanvas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mlt>=0:multimedia/py-mlt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg@${PY_FLAVOR} \
		scrollkeeper-install:textproc/rarian \
		sox:audio/sox

USES=		desktop-file-utils gettext python:2.7 shared-mime-info
USE_GNOME=	pygtk2
USE_PYTHON=	distutils
INSTALLS_OMF=	yes
NO_ARCH=	yes

post-patch:
	@${FIND} ${WRKSRC}/docs/omf -name '*.omf' | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|g'

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/omf/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/docs/omf/*.omf ${STAGEDIR}${PREFIX}/share/omf/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome/help/${PORTNAME}
	@cd ${WRKSRC}/docs/gnome && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/gnome/help/${PORTNAME}

.include <bsd.port.mk>
