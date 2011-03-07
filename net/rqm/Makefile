# New ports collection makefile for:	rqm
# Date created:		30 January 2000
# Whom:			fenner
#
# $FreeBSD$
#

PORTNAME=	rqm
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	net mbone tk
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/rqm/1.0.0/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical RTP quality monitor

DEPRECATED=	Unmaintained, anachronistic, mail freebsd-ports@FreeBSD.org if interested
EXPIRATION=	2011-06-30

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
BUILD_DEPENDS=	${LOCALBASE}/lib/libuclmmbase.a:${PORTSDIR}/devel/uclmmbase

WRKSRC=		${WRKDIR}/rqm/

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX} X11BASE=${LOCALBASE}

ALL_TARGET=	rqm
PLIST_FILES=	bin/rqm
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rqm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
