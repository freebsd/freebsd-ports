# New ports collection makefile for:  slush
# Date created:		Sun May 3, 1999
# Whom:			shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	firewalk
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://www.packetfactory.net/firewalk/dist/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

WRKSRC=		${WRKDIR}/Firewalk-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gtk=no

MAN1=		firewalk.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 300000
BROKEN=		may not build
.endif

.include <bsd.port.post.mk>
