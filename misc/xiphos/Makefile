# New ports collection makefile for: xiphos
# Date created:   February 2, 2009
# Whom:           Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xiphos
PORTVERSION=	3.1.3
PORTREVISION=	3
CATEGORIES=	misc gnome
MASTER_SITES=	SF/gnomesword/Xiphos/${PORTVERSION}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A bible interface utilizing the sword framework

RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.6.1.so:${PORTSDIR}/misc/sword
BUILD_DEPENDS=	${RUN_DEPENDS} \
		gnome-doc-tool:${PORTSDIR}/textproc/gnome-doc-utils \
		nspr>=4.8:${PORTSDIR}/devel/nspr

USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gnomelibs gtkhtml3 \
		intlhack libgsf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/nspr" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--disable-maintainer-mode --without-gecko

.include <bsd.port.mk>
