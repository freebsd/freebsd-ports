# New ports collection makefile for:    mswordview
# Version required:     0.5.14
# Date created:         Fri Nov  6 09:06:33 PST 1998
# Whom:                 sumikawa@kame.net
#
# $FreeBSD$
#

DISTNAME=	mswordview-0.5.14-bw6
PKGNAME=	mswordview-0.5.14.6
CATEGORIES=	textproc
MASTER_SITES=	http://www.csn.ul.ie/~caolan/publink/mswordview/

MAINTAINER=	sumikawa@kame.net

BUILD_DEPENDS=	${LOCALBASE}/lib/libwmf.a:${PORTSDIR}/graphics/libwmf

WRKSRC=		${WRKDIR}/mswordview
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ttf=${LOCALBASE} --with-wmf=${LOCALBASE}
USE_XLIB=	yes

MAN1=	mswordview.1

.include <bsd.port.mk>
