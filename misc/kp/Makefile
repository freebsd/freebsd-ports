# New ports collection makefile for:    kp
# Version required:     0.95
# Date created:         8 May 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.3 1995/11/26 10:47:46 asami Exp $
#

DISTNAME=       kp-0.95
CATEGORIES+=	misc
MASTER_SITES=   ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	asami@FreeBSD.org

RUN_DEPENDS=   wish:${PORTSDIR}/x11/tk

USE_X11=	yes

post-install:
	gzip -9nf ${PREFIX}/man/man1/kp.1

.include <bsd.port.mk>
