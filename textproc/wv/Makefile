# New ports collection makefile for:    wv
# Date created:         Fri Nov  6 09:06:33 PST 1998
# Whom:                 sumikawa@kame.net
#
# $FreeBSD$
#

PORTNAME=	wv
PORTVERSION=	0.7.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wvware

MAINTAINER=	mzaki@e-mail.ne.jp
COMMENT=	A library and executables to access Microsoft Word files

LIB_DEPENDS=	wmf.2:${PORTSDIR}/graphics/libwmf
RUN_DEPENDS=	lynx:${PORTSDIR}/www/lynx

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-exporter --without-glib
MAKEFILE=	GNUmakefile
INSTALLS_SHLIB=	yes

MAN1=	wvAbw.1 wvCleanLatex.1 wvDVI.1 wvHtml.1 wvLatex.1 wvMime.1 wvPDF.1 \
	wvPS.1 wvRTF.1 wvSummary.1 wvText.1 wvVersion.1 wvWare.1 wvWml.1
MLINKS=	wvWare.1 wvConvert.1

CPPFLAGS=	-I${LOCALBASE}/include/libpng -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/HAVE_MALLOC_H/d' ${WRKSRC}/config.h.in

.include <bsd.port.mk>
