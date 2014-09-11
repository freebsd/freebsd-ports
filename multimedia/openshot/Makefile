# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	openshot
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://launchpad.net/openshot/${PORTVERSION:C/\.[0-9]+$//}/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Non-linear video editor

LICENSE=	GPLv3

RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
		frei0r-plugins>=0:${PORTSDIR}/graphics/frei0r-plugins \
		${PYTHON_PKGNAMEPREFIX}goocanvas>=0:${PORTSDIR}/graphics/py-goocanvas \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0:${PORTSDIR}/www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}mlt>=0:${PORTSDIR}/multimedia/py-mlt \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:${PORTSDIR}/devel/py-xdg \
		scrollkeeper-install:${PORTSDIR}/textproc/rarian \
		sox:${PORTSDIR}/audio/sox

USE_GNOME=	pygtk2
USE_PYTHON=	2
USE_PYDISTUTILS=yes
USES=		desktop-file-utils gettext shared-mime-info
INSTALLS_OMF=	yes

post-patch:
	@${FIND} ${WRKSRC}/docs/omf -name '*.omf' | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|g'

pre-install:
	(${MKDIR} ${STAGEDIR}${PREFIX}/share/omf/${PORTNAME} && \
		cd ${WRKSRC}/docs/omf && ${COPYTREE_SHARE} \*.omf ${STAGEDIR}${PREFIX}/share/omf/${PORTNAME})
	(${MKDIR} ${STAGEDIR}${PREFIX}/share/gnome/help/${PORTNAME} && \
		cd ${WRKSRC}/docs/gnome && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share/gnome/help/${PORTNAME})

.include <bsd.port.mk>
