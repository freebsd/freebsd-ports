# ex:ts=8
# Ports collection makefile for:	partysip
# Date Created:			Mar 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	partysip
PORTVERSION=	2.0.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of a SIP proxy server

BUILD_DEPENDS=	pthread-config:${PORTSDIR}/devel/pth
LIB_DEPENDS=	osip2.2:${PORTSDIR}/net/libosip2 \
		gdbm.3:${PORTSDIR}/databases/gdbm
RUN_DEPENDS=	pthread-config:${PORTSDIR}/devel/pth

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-pth=yes --with-db=gdbm
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
