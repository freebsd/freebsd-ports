# New ports collection makefile for:	PiTiVi
# Date created:				20 Dec 2004
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/pitivi/Makefile,v 1.8 2006/04/26 19:31:01 ahze Exp $

PORTNAME=	pitivi
PORTVERSION=	0.13.4.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gstreamer based non-linear audio/video editor

RUN_DEPENDS=	py*-zopeInterface>=0:${PORTSDIR}/devel/py-zopeInterface \
		${PYTHON_SITELIBDIR}/goocanvasmodule.so:${PORTSDIR}/graphics/py-goocanvas

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pygtk2 pkgconfig
USE_GSTREAMER=	gnonlin python good
USE_PYTHON=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBAES}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--localstatedir=/var
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${LOCALBASE}/bin/python|g' \
		${WRKSRC}/bin/pitivi.in

.include <bsd.port.mk>
