# New ports collection makefile for:  slush
# Date created:		Sun May 3, 1999
# Whom:			shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	firewalk
PORTVERSION= 	0.9.9b
CATEGORIES=	security net
MASTER_SITES=	http://www.packetfactory.net/firewalk/
DISTNAME=	firewalk-0.99beta

MAINTAINER=	shipley@dis.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

MAN1=		firewalk.1

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib"
CONFIGURE_ARGS=	--with-gtk=no

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 300000
BROKEN=		may not build
.endif

WRKSRC=		${WRKDIR}/Firewalk-0.99b-beta3

.include <bsd.port.post.mk>
