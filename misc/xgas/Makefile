# New ports collection makefile for:    xgas
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xgas
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/demos
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The animated simulation of an ideal gas

USE_IMAKE=	yes
MAN1=		xgas.1

post-install:
	@${CHMOD} 755 ${PREFIX}/bin/xgas
	@${CHOWN} bin:bin ${PREFIX}/bin/xgas

.include <bsd.port.mk>
