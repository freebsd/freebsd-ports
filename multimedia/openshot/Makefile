# ex:ts=8
# Ports collection makefile for:	openshot
# Date created:		2011-02-05
# Whom:			Charlie Kester <corky1951@comcast.net>
#
# $FreeBSD$
#

PORTNAME=		openshot
PORTVERSION=		1.3.0
CATEGORIES=		multimedia
MASTER_SITES=		http://launchpad.net/openshot/${PORTMAJORVERSION}/${PORTVERSION}/+download/

MAINTAINER=		corky1951@comcast.net
COMMENT=		A non-linear video editor

RUN_DEPENDS=		ffmpeg:${PORTSDIR}/multimedia/ffmpeg \
			${LOCALBASE}/include/frei0r.h:${PORTSDIR}/graphics/frei0r \
			${PYTHON_SITELIBDIR}/goocanvasmodule.so:${PORTSDIR}/graphics/py-goocanvas \
			${PYTHON_SITELIBDIR}/httplib2/__init__.py:${PORTSDIR}/www/py-httplib2 \
			${PYTHON_SITELIBDIR}/_mlt.so:${PORTSDIR}/multimedia/py-mlt \
			${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
			scrollkeeper-install:${PORTSDIR}/textproc/scrollkeeper \
			sox:${PORTSDIR}/audio/sox

USE_GNOME=		pygtk2 desktopfileutils
USE_PYTHON=		2.5+
USE_PYDISTUTILS=	yes
USE_GETTEXT=		yes
INSTALLS_OMF=		yes

LICENSE=		GPLv3
MAN1=			${PORTNAME}.1 \
			${PORTNAME}-render.1
MANCOMPRESSED=		no
FETCH_ARGS=		-pRr
PORTMAJORVERSION=	1.3

post-patch:
	@${FIND} ${WRKSRC}/docs/omf -name '*.omf' | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|g'

pre-install:
	(${MKDIR} ${PREFIX}/share/omf/${PORTNAME} && \
		cd ${WRKSRC}/docs/omf && ${COPYTREE_SHARE} \*.omf ${PREFIX}/share/omf/${PORTNAME})
	(${MKDIR} ${PREFIX}/share/gnome/help/${PORTNAME} && \
		cd ${WRKSRC}/docs/gnome && ${COPYTREE_SHARE} \* ${PREFIX}/share/gnome/help/${PORTNAME})

.include <bsd.port.mk>
