# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pitivi
PORTVERSION=	0.13.4.2
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gstreamer based non-linear audio/video editor

LICENSE=	LGPL21+

RUN_DEPENDS=	py*-zope.interface>=0:devel/py-zope.interface \
		${PYTHON_SITELIBDIR}/goocanvasmodule.so:graphics/py-goocanvas

USES=		gettext gmake localbase pkgconfig python:2.7 shebangfix tar:bzip2
SHEBANG_FILES=	bin/pitivi.in
USE_GNOME=	intltool pygtk2
USE_GSTREAMER=	gnonlin python good
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_LDCONFIG=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
