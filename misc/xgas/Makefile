#New ports collection makefile for:    xgas
# Version required:     
# Date created:         20 Oct 1996
# Whom:                 Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/11/15 09:55:44 asami Exp $
#

DISTNAME=	xgas
PKGNAME=        xgas-1.0
CATEGORIES=     misc
MASTER_SITES=   ftp://ftp.tut.ac.jp/.h3/X11/X11R6/contrib/programs/

MAINTAINER=     nakai@mlab.t.u-tokyo.ac.jp

USE_IMAKE=      yes
MAN1=		xgas.1

post-install:
	@chmod 755 ${PREFIX}/bin/xgas
	@chown bin.bin ${PREFIX}/bin/xgas

.include <bsd.port.mk>
