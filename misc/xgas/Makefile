# New ports collection makefile for:    xgas
# Version required:     1.0
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	xgas
PKGNAME=	xgas-1.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/demos

MAINTAINER=	nacai@iname.com

USE_IMAKE=	yes
MAN1=		xgas.1

post-install:
	@${CHMOD} 755 ${PREFIX}/bin/xgas
	@${CHOWN} bin.bin ${PREFIX}/bin/xgas

.include <bsd.port.mk>
