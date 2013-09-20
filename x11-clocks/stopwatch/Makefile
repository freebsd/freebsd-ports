# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	stopwatch
PORTVERSION=	3.5
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://expect.nist.gov/stopwatch/
DISTNAME=	stopwatch

MAINTAINER=	edwin@mavetju.org
COMMENT=	Stopwatch enables hand timing much like a physical stopwatch

WRKSRC=		${WRKDIR}/${PORTNAME}-3.4
USE_TK_RUN=	yes
USE_TK_WRAPPER=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/stopwatch

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/stopwatch

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/stopwatch ${PREFIX}/bin

.include <bsd.port.mk>
