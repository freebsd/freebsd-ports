# New ports collection makefile for:	amanda
# Version required:			2.3.0
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

DISTNAME=	amanda-2.3.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cs.umd.edu/pub/amanda/old-versions/

MAINTAINER=	ports@FreeBSD.org

PATCH_STRIP=
MAN8=		amanda.8 amadmin.8 amcheck.8 amcleanup.8 amdump.8 \
		amflush.8 amlabel.8 amrestore.8  amtape.8

pre-configure:
	${ECHO} "${CFLAGS}" > /tmp/build-ports-misc-amanda-cflags

post-install:
	${MKDIR} ${PREFIX}/share/examples/amanda
	${CP} -R ${WRKSRC}/example/* ${PREFIX}/share/examples/amanda

.include <bsd.port.mk>
