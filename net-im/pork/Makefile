# Created by: Bob Bomar <bob@bomar.us>
# $FreeBSD$

PORTNAME=	pork
PORTVERSION=	0.99.8.1
CATEGORIES=	net-im
MASTER_SITES=	SF/ojnk/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console-based AIM client

USES=		ncurses perl5
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/^inline //' ${WRKSRC}/src/*.h

.include <bsd.port.mk>
