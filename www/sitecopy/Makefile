# New ports collection makefile for:	sitecopy
# Date created:		15 January 1999
# Whom:			nik
#
# $FreeBSD$
#

PORTNAME=	sitecopy
PORTVERSION=	0.10.14
CATEGORIES=	www
MASTER_SITES=	http://www.lyra.org/sitecopy/

MAINTAINER=	nik@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		expat.1:${PORTSDIR}/textproc/expat \
		neon.9:${PORTSDIR}/www/neon

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LDFLAGS=-L${LOCALBASE}/lib \
		LIBS=-lintl
USE_GMAKE=	yes
ALL_TARGET=	sitecopy

MAN1=		sitecopy.1

.include <bsd.port.mk>
