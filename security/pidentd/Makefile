# New ports collection makefile for:	pidentd
# Version required:     2.7.2
# Date created:		19 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.17 1996/11/05 18:23:42 peter Exp $
#

DISTNAME=       pidentd-2.7.2
CATEGORIES+=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/servers/ \
		ftp://ftp.fu-berlin.de/unix/security/ident/servers/

MAINTAINER=	torstenb@FreeBSD.ORG

ALL_TARGET=     freebsd
MAKE_ENV=	REALPREFIX=${PREFIX}

# Uncomment to activate the use of verifiable "cookies".  The idea is to be
# able to detect fake "logs" intended to get your innocent users in trouble.
# Naturally, since it uses libdes, you must have the "secure" dist installed.
USE_DES=	true

.if defined(USE_DES)
ADD_GDEFS=	-DINCLUDE_CRYPT
ADD_GLIBS=	-ldes
MAKE_ENV+=	ADD_GDEFS="${ADD_GDEFS}" ADD_GLIBS="${ADD_GLIBS}"
.endif

.if !defined(NOMANCOMPRESS)
post-install:
	gzip -9nf ${PREFIX}/man/man8/identd.8
	gzip -9nf ${PREFIX}/man/man8/idecrypt.8
.endif

.include <bsd.port.mk>
