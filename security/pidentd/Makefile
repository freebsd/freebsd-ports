# New ports collection makefile for:	pidentd
# Version required:     2.8.5
# Date created:		19 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

DISTNAME=       pidentd-2.8.5
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/servers/ \
		ftp://ftp.fu-berlin.de/unix/security/ident/servers/

MAINTAINER=	torstenb@FreeBSD.org

ALL_TARGET=     freebsd
MAKE_ENV=	REALPREFIX=${PREFIX}
MAN8=		identd.8 idecrypt.8

# Uncomment to activate the use of verifiable "cookies".  The idea is to be
# able to detect fake "logs" intended to get your innocent users in trouble.
# Naturally, since it uses libdes, you must have the "secure" dist installed.
# USE_DES=	true

.if defined(USE_DES)
ADD_GDEFS=	-DINCLUDE_CRYPT
ADD_GLIBS=	-ldes
MAKE_ENV+=	ADD_GDEFS="${ADD_GDEFS}" ADD_GLIBS="${ADD_GLIBS}"
.endif

.include <bsd.port.mk>
