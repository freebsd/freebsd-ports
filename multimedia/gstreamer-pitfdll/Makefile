# New ports collection makefile for:	gstreamer plugins pitfdll
# Date created:		08 Oct 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-pitfdll/Makefile,v 1.7 2006/07/23 18:28:35 marcus Exp $

PORTNAME=	gstreamer-pitfdll
PORTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pitfdll
DISTNAME=	pitfdll-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer DLL loader plugin

RUN_DEPENDS=	${LOCALBASE}/lib/win32/wmv8ds32.ax:${PORTSDIR}/multimedia/win32-codecs

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
USE_GSTREAMER80=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	VERSION="${GST80_VERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/win32|${LOCALBASE}/lib/win32|g' \
		${WRKSRC}/ext/pitfdll/Makefile.in \
		${WRKSRC}/gst-libs/ext/loader/wine/Makefile.in

post-install:
# register plugins
	-@${LOCALBASE}/bin/gst-register-${GST_VERSION} \
		--gst-registry=${PREFIX}/share/gnome/cache/gstreamer-${GST_VERSION}/registry.xml 2>/dev/null

.include <bsd.port.mk>
