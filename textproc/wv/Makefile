# New ports collection makefile for:    wv
# Date created:         Fri Nov  6 09:06:33 PST 1998
# Whom:                 sumikawa@kame.net
#
# $FreeBSD$
#

PORTNAME=	wv
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wvware

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library and executables to access Microsoft Word files

LIB_DEPENDS=	wmf.2:${PORTSDIR}/graphics/libwmf
.if defined(WITHOUT_SSL)
RUN_DEPENDS=	lynx:${PORTSDIR}/www/lynx
.else
RUN_DEPENDS=	lynx:${PORTSDIR}/www/lynx-ssl
.endif

USE_GETOPT_LONG=	yes
USE_GNOME=	gnometarget pkgconfig glib20
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-exporter \
		--with-glib=glib2 \
		--with-libwmf=${LOCALBASE}
MAKEFILE=	GNUmakefile
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
INSTALLS_SHLIB=	yes

MAN1=	wvAbw.1 wvCleanLatex.1 wvDVI.1 wvHtml.1 wvLatex.1 wvMime.1 wvPDF.1 \
	wvPS.1 wvRTF.1 wvSummary.1 wvText.1 wvVersion.1 wvWare.1 wvWml.1
MLINKS=	wvWare.1 wvConvert.1

CPPFLAGS=	-I${LOCALBASE}/include/libpng -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
