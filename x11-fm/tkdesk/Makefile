# New ports collection makefile for:	tkdesk
# Version required:     1.0b2
# Date created:         30 Jul 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $Id: Makefile,v 1.1.1.1 1996/08/02 19:57:31 chuckr Exp $
#

DISTNAME=	tkdesk-1.0b2
PKGNAME=	tkdesk-1.0
CATEGORIES+=	misc x11
MASTER_SITES=	http://sun1.rrzn-user.uni-hannover.de/~zzhibol/tkdesk/
DISTFILES=	tkdesk-1.0b2.tar.gz sounds.tar.gz

MAINTAINER=	shanee@rabbit.augusta.de

EXTRACT_ONLY=	tkdesk-1.0b2.tar.gz

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

post-extract:
	cd ${WRKDIR}/tkdesk-1.0b2/tcldesk/;tar -xzf $(DISTDIR)/sounds.tar.gz

.include <bsd.port.mk>
