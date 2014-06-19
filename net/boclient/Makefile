# Created by: darius@dons.net.au
# $FreeBSD$

PORTNAME=	boclient
PORTVERSION=	1.21
CATEGORIES=	net security
MASTER_SITES=	http://www.cultdeadcow.com/tools/
DISTNAME=	bo121unix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client program for the Back Orifice Windows program

PLIST_FILES=	bin/bounix
WRKSRC=		${WRKDIR}/bo
GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bounix

.include <bsd.port.mk>
