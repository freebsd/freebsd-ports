# New ports collection makefile for:    kp
# Date created:         8 May 1995
# Whom:                 asami
#
# $FreeBSD$
#

PORTNAME=	kp
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Keyboard Practicer, touch-type training program

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_MOTIF=	yes
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xp xpm xt
MAN1=		kp.1

post-install:
	${MKDIR} ${PREFIX}/share/kp/xmodmaps
	cd ${WRKSRC}; ${INSTALL_DATA} COPYRIGHT README ${PREFIX}/share/kp
	cd ${WRKSRC}/xmodmaps; ${INSTALL_DATA} * ${PREFIX}/share/kp/xmodmaps

.include <bsd.port.mk>
