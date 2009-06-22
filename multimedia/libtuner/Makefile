# New ports collection makefile for:	libtuner
# Date created:		7 September 2008
# Whom:			jah
#
# $FreeBSD$
#

PORTNAME=	libtuner
PORTVERSION=	1.0.3
CATEGORIES=	multimedia
MASTER_SITES=	ftp://corona.homeunix.net/ports/libtuner/
EXTRACT_ONLY=	libtuner-${PORTVERSION}.tar.gz

MAINTAINER=	jason.harmening@gmail.com
COMMENT=	Userspace drivers for various TV/radio tuner ICs

MAKE_ARGS+=	LIBTUNER_MAJOR=1 LIBTUNER_MINOR=0 LIBTUNER_REV=3 INSTALLDIR=${PREFIX}
USE_LDCONFIG=	${PREFIX}/lib/libtuner

.include <bsd.port.mk>
