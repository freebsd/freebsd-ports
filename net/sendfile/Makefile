# New ports collection makefile for:    sendfile
# Version required:     2.1
# Date created:         30 Oct 1997
# Whom:                 sec@42.org
#
# $Id: Makefile,v 1.8 1999/02/23 15:25:30 joerg Exp $
#

DISTNAME=	sendfile-19990215
PKGNAME=	sendfile-2.1
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.uni-stuttgart.de/pub/unix/comm/sendfile/current/

MAINTAINER=	sec@42.org

BROKEN= 'single mastersite unreachable'

WRKSRC=		${WRKDIR}/${PKGNAME}
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=makeconfig
CONFIGURE_ENV=	PREFIX="${PREFIX}"

MAN1=		sendfile.1 sendmsg.1 receive.1 fetchfile.1 utf7encode.1 \
		wlock.1
MAN7=		fetchfile.7
MAN8=		sendfiled.8

post-install:
	@(cd ${PREFIX}/man/man1; ln -sf utf7encode.1.gz utf7decode.1.gz)

.include <bsd.port.mk>
