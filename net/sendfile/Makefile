# New ports collection makefile for:    sendfile
# Version required:     2.1
# Date created:         23 February 1998
# Whom:                 sec@42.org
#
# $Id$
#

DISTNAME=       sendfile-2.1
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.uni-stuttgart.de/pub/unix/comm/sendfile/current/

MAINTAINER=	sec@42.org

WRKSRC=		${WRKDIR}/${PKGNAME}

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=makeconfig
CONFIGURE_ENV=	PREFIX="${PREFIX}"

MAN1=		sendfile.1 sendmsg.1 receive.1

.include <bsd.port.mk>
