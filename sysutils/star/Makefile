# New ports collection makefile for:	star
# Version required:	1,0
# Date created:		Thu May  1 20:28:44 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id$
#

DISTNAME=	star-1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/star/

MAINTAINER=	andreas@FreeBSD.org

USE_GMAKE=	yes
MAKE_ENV+=	MAKEPROG=gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/star/OBJ/i386-freebsd-cc/star ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/star/star.1 ${PREFIX}/man/man1
.if !defined(NOMANCOMPRESS)
	@${ECHO_MSG} "===>   Compressing manual pages for ${PKGNAME}"
	@${GZIP_CMD} ${PREFIX}/man/man1/star.1
.endif

.include <bsd.port.mk>
