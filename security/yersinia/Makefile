# New ports collection makefile for:    yersinia
# Date created:         Sun Jul 24 10:43:13 CEST 2005
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	yersinia
PORTVERSION=	0.5.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}

MAINTAINER=	se@FreeBSD.org
COMMENT=	Layer 2 vulnerability scanner (switches, spanning tree, 802.1q ...)

# Dependency on file that is not also installed by libnet (1.0.2) port!
BUILD_DEPENDS=	${LOCALBASE}/share/examples/libnet/ip_raw.c:${PORTSDIR}/net/libnet-devel

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

NOT_FOR_ARCHS=	ia64 sparc64
MAN8=		yersinia.8
CFLAGS+=	-DNEED_GETOPT_H
PLIST_FILES=	sbin/yersinia

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/yersinia ${PREFIX}/sbin/
		${INSTALL_MAN} ${WRKSRC}/yersinia.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
