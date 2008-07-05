# New ports collection makefile for:	wbxml
# Date created:			Nov 04, 2005
# Whom:				Clemens Zauner <czauner+ports@onlineloop.com>
#
# $FreeBSD$
#

PORTNAME=	wbxml2
PORTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://czauner.onlineloop.com/pub/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	wbxmllib
DISTNAME=	wbxml2-${PORTVERSION}

MAINTAINER=	czauner+ports@onlineloop.com
COMMENT=	Library & tools for converting wbxml<->xml

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	aclocal:19 autoconf:261 autoheader:261 automake:19 libtool:15
AUTOMAKE_ARGS=	-acf
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig libxml2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

patch-autotools:
	@${CP} ${LOCALBASE}/share/libtool/ltmain.sh ${WRKSRC}/ltmain.sh
	@${CAT} ${LOCALBASE}/share/aclocal/libtool.m4 >> ${WRKSRC}/aclocal.m4
	@${TOUCH} ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} 's|^.*install_prog.*instname.*destdir.*$$||' ${WRKSRC}/ltmain.sh

.include <bsd.port.mk>
