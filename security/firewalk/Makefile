# New ports collection makefile for:  slush
# Date created:		Sun May 3, 1999
# Whom:			shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	firewalk
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://www.packetfactory.net/firewalk/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

MAN1=		firewalk.1

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib"
CONFIGURE_ARGS=	--with-gtk=no

WRKSRC=		${WRKDIR}/Firewalk-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 300000
BROKEN=		may not build
.endif

.include <bsd.port.post.mk>
