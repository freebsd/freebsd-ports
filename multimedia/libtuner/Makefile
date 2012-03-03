# New ports collection makefile for:   libtuner
# Date created:        7 September 2008
# Whom:                jah
#
# $FreeBSD$
#

PORTNAME=	libtuner
PORTVERSION=	1.0.8
CATEGORIES=	multimedia
MASTER_SITES=	ftp://corona.homeunix.net/ports/libtuner/

MAINTAINER=	jason.harmening@gmail.com
COMMENT=	Userspace drivers for various TV/radio tuner ICs

LICENSE=	BSD

MAKE_ARGS+=	LIBTUNER_MAJOR=1 LIBTUNER_MINOR=0 LIBTUNER_REV=${PORTVERSION:E} INSTALLDIR=${PREFIX}
USE_LDCONFIG=	${PREFIX}/lib/libtuner

.include <bsd.port.mk>
