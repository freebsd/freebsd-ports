# New ports collection makefile for:	fung-calc
# Date created:				10.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	fung-calc
PORTVERSION=	1.3.2b
PORTREVISION=	4
CATEGORIES=	math kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Advanced graphic calculator

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut

USE_KDELIBS_VER=	3
USE_GL=		yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

pre-configure:
	@${REINPLACE_CMD} -e 's|-O2|-fPIC|g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
