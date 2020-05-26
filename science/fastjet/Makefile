# $FreeBSD$

PORTNAME=	fastjet
DISTVERSION=	3.3.4
CATEGORIES=	science
MASTER_SITES=	http://fastjet.fr/repo/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for jet finding in pp and e+e- collisions

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

LDFLAGS+=	-lexecinfo

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>
