# New ports collection makefile for:   	centericq
# Date created:                        	25 December 1999
# Whom:                                 Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	centericq
PORTVERSION=	2.0.0
CATEGORIES=	net
MASTER_SITES=	http://konst.org.ua/download/
DISTNAME=	center-${PORTVERSION}

MAINTAINER=	cpiazza@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 400010
LIB_DEPENDS=	ncurses.4:${PORTSDIR}/devel/ncurses
CFLAGS+=	-nostdinc -I${LOCALBASE}/include/ncurses -I${LOCALBASE}/include\
		-I/usr/include
.endif

WRKSRC=		${WRKDIR}/center
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e 's:__PREFIX__:${PREFIX}:' ${WRKSRC}/centerICQ.cc

pre-build:
	@(cd ${WRKDIR}/ktools/src; ${SETENV} CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" ${GMAKE} ${MAKE_ARGS} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/center ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/center
	${INSTALL_DATA} ${WRKSRC}/sound/* ${PREFIX}/share/center

.include <bsd.port.post.mk>
