# New ports collection makefile for:    kp
# Version required:     0.96
# Date created:         8 May 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.5 1996/10/16 08:55:30 asami Exp $
#

DISTNAME=       kp-0.96
CATEGORIES=	misc
MASTER_SITES=   ftp://stampede.cs.berkeley.edu/pub/kp/

MAINTAINER=	asami@FreeBSD.org

RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41

USE_X11=	yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/kp.1
.endif

.include <bsd.port.mk>
