# New ports collection makefile for:	PilRC
# Date created:		29 Mar 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pilrc
PORTVERSION= 	2.5b1
CATEGORIES=	palm
MASTER_SITES=	http://www.hig.se/~ardiri/development/palmIII/pilrc/
DISTNAME=	pilrcsrc

MAINTAINER=	kuriyama@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		glib12.3:${PORTSDIR}/devel/glib12

USE_ZIP=	YES
NO_WRKSUBDIR=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pilrc ${WRKSRC}/pilrcui ${PREFIX}/bin

.include <bsd.port.mk>
