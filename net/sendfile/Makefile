# New ports collection makefile for:    sendfile
# Version required:     2.1
# Date created:         30 Oct 1997
# Whom:                 sec@42.org
#
# $Id: Makefile,v 1.1.1.1 1998/02/24 20:28:16 steve Exp $
#

DISTNAME=	sendfile-19980228
PKGNAME=	sendfile-2.1
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.uni-stuttgart.de/pub/unix/comm/sendfile/current/

MAINTAINER=	sec@42.org

WRKSRC=		${WRKDIR}/${PKGNAME}
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=makeconfig
CONFIGURE_ENV=	PREFIX="${PREFIX}"

MAN1=		sendfile.1 sendmsg.1 receive.1 fetchfile.1
MAN7=		fetchfile.7
MAN8=		sendfiled.8

.include <bsd.port.mk>
