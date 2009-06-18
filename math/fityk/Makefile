# ex:ts=8
# Ports collection makefile for:	fityk
# Date created:			Mar 8, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fityk
PORTVERSION=	0.8.7
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free peak fitting software

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_WX=		2.8+
WX_CONF_ARGS=	absolute
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

MAN1=		fityk.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
