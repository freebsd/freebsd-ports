# New ports collection makefile for:    wv
# Date created:         Fri Nov  6 09:06:33 PST 1998
# Whom:                 sumikawa@kame.net
#
# $FreeBSD$
#

PORTNAME=	wv
PORTVERSION=	0.6.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wvware

MAINTAINER=	mzaki@e-mail.ne.jp

LIB_DEPENDS=	wmf.1:${PORTSDIR}/graphics/libwmf

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ttf=${LOCALBASE} --with-wmf=${LOCALBASE} \
		--with-png=${LOCALBASE} --with-xpm=${X11BASE}
USE_GMAKE=	yes
USE_XLIB=	yes

MAN1=	wvAbw.1 wvCleanLatex.1 wvDVI.1 wvHtml.1 wvLatex.1 wvMime.1 \
	wvPDF.1 wvPS.1 wvSummary.1 wvText.1 wvVersion.1 wvWare.1 wvWml.1
MLINKS=	wvWare.1 wvConvert.1

.include <bsd.port.mk>
