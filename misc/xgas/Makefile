# New ports collection makefile for:    xgas
# Version required:     1.0
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1998/10/04 22:41:24 steve Exp $
#

DISTNAME=	xgas
PKGNAME=	xgas-1.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.tut.ac.jp/.h3/X11/X11R6/contrib/programs/

MAINTAINER=	nacai@iname.com

USE_IMAKE=	yes
MAN1=		xgas.1

post-install:
	@chmod 755 ${PREFIX}/bin/xgas
	@chown bin.bin ${PREFIX}/bin/xgas

.include <bsd.port.mk>
