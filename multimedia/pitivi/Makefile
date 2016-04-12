# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/pitivi/Makefile,v 1.8 2006/04/26 19:31:01 ahze Exp $

PORTNAME=	pitivi
PORTVERSION=	0.13.4.2
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gstreamer based non-linear audio/video editor

RUN_DEPENDS=	py*-zope.interface>=0:devel/py-zope.interface \
		${PYTHON_SITELIBDIR}/goocanvasmodule.so:graphics/py-goocanvas

USES=		gettext gmake pkgconfig python tar:bzip2
USE_GNOME=	intltool pygtk2
USE_GSTREAMER=	gnonlin python good
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--localstatedir=/var
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${LOCALBASE}/bin/python|g' \
		${WRKSRC}/bin/pitivi.in

.include <bsd.port.mk>
