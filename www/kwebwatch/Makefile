# New ports collection makefile for:		kwebwatch
# Date created:         11 June 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	kwebwatch
PORTVERSION=	0.72
CATEGORIES=	www kde
MASTER_SITES=	http://linuxberg.uol.com.br/files/kde/network/ \
		http://www.kde.gr.jp/~hanawa/apps/kwebwatch/

MAINTAINER=	lioux@linf.unb.br

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		kdeui.3:${PORTSDIR}/x11/kdelibs11 \
		kfile.3:${PORTSDIR}/x11/kdelibs11 \
		kfm.3:${PORTSDIR}/x11/kdelibs11

USE_XLIB=	yes
USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
