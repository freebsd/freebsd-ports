# New ports collection makefile for:    mswordview
# Date created:         Fri Nov  6 09:06:33 PST 1998
# Whom:                 sumikawa@kame.net
#
# $FreeBSD$
#

PORTNAME=	mswordview
PORTVERSION=	0.5.14.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.csn.ul.ie/~caolan/publink/mswordview/
DISTNAME=	${PORTNAME}-0.5.14-bw6

MAINTAINER=	sumikawa@FreeBSD.org

LIB_DEPENDS=	wmf.1:${PORTSDIR}/graphics/libwmf

WRKSRC=		${WRKDIR}/mswordview
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ttf=${LOCALBASE} --with-wmf=${LOCALBASE}
USE_XLIB=	yes

MAN1=	mswordview.1

.include <bsd.port.mk>
