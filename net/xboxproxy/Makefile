# New ports collection makefile for:	xboxproxy
# Date created:		6 October 2005
# Whom:			Antony Mawer <ports@mawer.org>
#
# $FreeBSD$

PORTNAME=	xboxproxy
PORTVERSION=	1.9
CATEGORIES=	net
MASTER_SITES=	http://www.csh.rit.edu/~psionic/projects/xboxproxy/
DISTNAME=	proxy-${PORTVERSION}

MAINTAINER=	ports@mawer.org
COMMENT=	A proxy for the XBox system link protocol

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=xbox
USE_GMAKE=	yes

PLIST_FILES=	bin/xboxproxy

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Doesn't build on FreeBSD < 5.x"
.endif

.include <bsd.port.post.mk>
