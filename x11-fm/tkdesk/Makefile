# New ports collection makefile for:	tkdesk
# Version required:     1.0b2
# Date created:         30 Jul 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $Id: Makefile,v 1.3 1996/11/12 04:54:07 max Exp $
#

DISTNAME=	tkdesk-1.0b3
PKGNAME=	tkdesk-1.0b3
CATEGORIES=	misc x11 tk41
MASTER_SITES=	http://sun1.rrzn-user.uni-hannover.de/~zzhibol/tkdesk/

MAINTAINER=	nox@jelal.hb.north.de

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

post-patch:
	-rm ${WRKSRC}/tcldesk/*.orig ${WRKSRC}/tcldesk/*/*.orig

.include <bsd.port.mk>
