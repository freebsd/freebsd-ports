# New ports collection makefile for:	tkdesk
# Version required:     1.0b2
# Date created:         30 Jul 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $Id: Makefile,v 1.1.1.1 1996/08/02 19:57:31 chuckr Exp $
#

DISTNAME=	tkdesk-1.0b3
PKGNAME=	tkdesk-1.0b3
CATEGORIES=	misc x11
MASTER_SITES=	http://sun1.rrzn-user.uni-hannover.de/~zzhibol/tkdesk/

MAINTAINER=	nox@jelal.hb.north.de

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

post-patch:
	-rm ${WRKSRC}/tcldesk/*.orig ${WRKSRC}/tcldesk/*/*.orig

.include <bsd.port.mk>
