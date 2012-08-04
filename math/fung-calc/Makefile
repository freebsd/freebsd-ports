# New ports collection makefile for:	fung-calc
# Date created:				10.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	fung-calc
PORTVERSION=	1.3.2b
PORTREVISION=	15
CATEGORIES=	math kde
MASTER_SITES=	SF/${PORTNAME}/releases/${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Advanced graphic calculator

PORTSCOUT=	skipv:1.3.2	#This version is later then 1.3.2
USE_KDELIBS_VER=3
USE_GL=		glut
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

pre-configure:
	@${REINPLACE_CMD} -e 's|-O2|-fPIC|g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
