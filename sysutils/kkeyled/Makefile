# New ports collection makefile for:	kkeyled
# Date created:			Tue Mar  2 05:10:59 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kkeyled
PORTVERSION=	0.8.9
PORTREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.truesoft.ch/dieter/kkeyled/software/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Panel applet to display the keyboard's LED states

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|/opt/kde3|${PREFIX}|g' \
		${WRKSRC}/kkeyled/Themicons/kkeyledrc

.include <bsd.port.mk>
