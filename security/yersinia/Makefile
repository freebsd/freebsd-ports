# New ports collection makefile for:    yersinia
# Date created:         Sun Jul 24 10:43:13 CEST 2005
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	yersinia
PORTVERSION=	0.7
CATEGORIES=	security
MASTER_SITES=	http://www.yersinia.net/download/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Layer 2 vulnerability scanner (switches, spanning tree, 802.1q ...)

.include <bsd.port.pre.mk>

BUILD_DEPENDS=	libnet*>=1.1.2,1:${PORTSDIR}/net/libnet

.if ${OSVERSION} < 500000
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

NOT_FOR_ARCHS=	ia64 sparc64
MAN8=		yersinia.8
PLIST_FILES=	sbin/yersinia

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/yersinia ${PREFIX}/sbin/
		${INSTALL_MAN} ${WRKSRC}/yersinia.8 ${PREFIX}/man/man8/

.include <bsd.port.post.mk>
