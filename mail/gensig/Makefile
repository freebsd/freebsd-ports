# New ports collection makefile for:	gensig
# Date created:		6 August 1999
# Whom:			arensb@ooblick.com
#
# $FreeBSD$
#

PORTNAME=	gensig
PORTVERSION=	2.3
CATEGORIES=	mail
MASTER_SITES=	http://www.geekthing.com/~robf/ware/gensig/ \
		http://www.ooblick.com/software/gensig/

MAINTAINER=	arensb+freebsd-ports@ooblick.com
COMMENT=	A random .signature generator

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

USE_GETOPT_LONG=	yes

MAN1=		gensig.1 cattag.1

.include <bsd.port.mk>
