# New ports collection makefile for:	sitecopy
# Date created:		15 January 1999
# Whom:			nik
#
# $FreeBSD$
#

PORTNAME=	sitecopy
PORTVERSION=	0.10.15
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.lyra.org/sitecopy/

MAINTAINER=	olgeni@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		neon.12:${PORTSDIR}/www/neon

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib -lintl"
USE_GMAKE=	yes

MAN1=		sitecopy.1

.include <bsd.port.mk>
