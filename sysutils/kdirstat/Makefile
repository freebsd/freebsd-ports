# New ports collection makefile for:	kdirstat
# Date created:		25 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kdirstat
PORTVERSION=	2.3.7
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	http://kdirstat.sourceforge.net/download/

MAINTAINER=	stefan.jahn@nemesis-sektor.de
COMMENT=	A small KDE utility that sums up disk usage for direcory trees

USE_BZIP2=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
