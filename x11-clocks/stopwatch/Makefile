# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	stopwatch
PORTVERSION=	3.5
PORTREVISION=	2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://expect.nist.gov/stopwatch/
DISTNAME=	stopwatch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stopwatch enables hand timing much like a physical stopwatch

LICENSE=	PD

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

WRKSRC=		${WRKDIR}/${PORTNAME}-3.4
USES=		tk:run
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/stopwatch

post-patch:
	@${REINPLACE_CMD} -e "s,/depot/path/wish,${WISH}," ${WRKSRC}/stopwatch

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/stopwatch ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
