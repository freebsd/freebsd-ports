# New ports collection makefile for:	mcrypt
# Version required:	2.2
# Date created:		Mon Jun 28 18:02:04 PDT 1999
# Whom:			nsayer@freebsd.org
#
# $FreeBSD$
#

DISTNAME=	libmcrypt-2.2
CATEGORIES=	security
MASTER_SITES=	ftp://argeas.cs-net.gr/pub/unix/mcrypt/

MAINTAINER=	nsayer@freebsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-posix-threads

MAN3=		mcrypt.3

RESTRICTED=	"yes - cryptography"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
