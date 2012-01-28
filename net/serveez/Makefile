# ex:ts=8
# Ports collection makefile for:	serveez
# Date created:			May 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	serveez
PORTVERSION=	0.1.7
CATEGORIES=	net devel
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A server framework

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	guile.21:${PORTSDIR}/lang/guile

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-guile=${LOCALBASE}
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		serveez.1 serveez-config.1
INFO=		serveez serveez-api

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|test||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's| -release .*||' ${WRKSRC}/src/libserveez/Makefile.in

.include <bsd.port.mk>
