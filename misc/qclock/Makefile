# New ports collection makefile for:	 qclock
# Version required:	1.0
# Date created:		12 August 1998
# Whom:			brett@peloton.physics.montana.edu
#
# $Id: Makefile,v 1.1.1.1 1998/08/13 07:16:47 jkoshy Exp $
#

DISTNAME=	qclock
PKGNAME=	qclock-1.0
CATEGORIES=	misc
MASTER_SITES=	http://snowball.cypcopic.com.au/qclock/

MAINTAINER=	brett@peloton.physics.montana.edu

BROKEN=		fetch

NO_WRKSUBDIR=	yes

ALL_TARGET=	qclock

do-install:
	${CP} ${WRKDIR}/qclock ${PREFIX}/bin/qclock

.include <bsd.port.mk>
