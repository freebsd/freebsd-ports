# New ports collection makefile for:	ifile
# Date created:         29 Jan 2002
# Whom:                 David Bushong <david+ports@bushong.net>
#
# $FreeBSD$
#

PORTNAME=	ifile
PORTVERSION=	1.3.3
CATEGORIES=	mail textproc
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/default.pkg/${PORTVERSION}

MAINTAINER=	david+ports@bushong.net
COMMENT=	An application of machine learning to e-mail filtering

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN1=		ifile.1

.include <bsd.port.mk>
