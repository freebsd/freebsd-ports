# New ports collection makefile for:	rqm
# Date created:		30 January 2000
# Whom:			fenner
#
# $FreeBSD$
#

PORTNAME=	rqm
PORTVERSION=	1.0.0
CATEGORIES=	mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rqm/1.0.0/

MAINTAINER=	fenner@FreeBSD.org
COMMENT=	A graphical RTP quality monitor

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
BUILD_DEPENDS=	${LOCALBASE}/lib/libuclmmbase.a:${PORTSDIR}/devel/uclmmbase

WRKSRC=		${WRKDIR}/rqm/

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX} X11BASE=${X11BASE}

ALL_TARGET=	rqm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rqm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/rqm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/rqm
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

.include <bsd.port.post.mk>
