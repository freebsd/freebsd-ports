# ex:ts=8
# Ports collection makefile for:	partysip
# Date Created:			Mar 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	partysip
PORTVERSION=	2.1.1
CATEGORIES=	net
MASTER_SITES=	http://osip.atosc.org/download/partysip/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An implementation of a SIP proxy server

LIB_DEPENDS=	osip2.2:${PORTSDIR}/net/libosip2 \
		gdbm.3:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-db=gdbm
INSTALLS_SHLIB=	yes

BROKEN=		Does not link with libossip-2.0.7. Downgrade libossip to 2.0.6, uncomment BROKEN in Makefile and retry

.include <bsd.port.mk>
