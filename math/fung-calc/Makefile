# New ports collection makefile for:	fung-calc
# Date created:				10.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	fung-calc
PORTVERSION=	1.3.2b
PORTREVISION=	11
CATEGORIES=	math kde
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Advanced graphic calculator

USE_KDELIBS_VER=3
USE_GL=		glut
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

pre-configure:
	@${REINPLACE_CMD} -e 's|-O2|-fPIC|g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
