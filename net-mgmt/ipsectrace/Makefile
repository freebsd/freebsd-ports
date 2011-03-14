# New ports collection makefile for:	ipsectrace
# Date created:		2006-11-04
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	ipsectrace
PORTVERSION=	0.1.0
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://chewies.net/ \
		http://farrokhi.net/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPSEC Traffic Profiler

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS} -Wno-deprecated" \
		LDFLAGS="${LDFLAGS} -lpcap" INCLUDES="${INCLUDES}"
PLIST_FILES=	bin/ipsectrace

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,,g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,<hash_map>,<hash_map.h>,g' ${WRKSRC}/ipsectrace.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipsectrace ${PREFIX}/bin/ipsectrace

.include <bsd.port.mk>
