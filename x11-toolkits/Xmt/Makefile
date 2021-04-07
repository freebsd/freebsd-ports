PORTNAME=	Xmt
PORTVERSION=	4.0.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/motiftools/Xmt/Xmt400
DISTNAME=	xmt400

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Motif Tools library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

WRKSRC=		${WRKDIR}/xmt400

USES=		motif imake tar:tgz
USE_LDCONFIG=	yes

post-patch:
	${TOUCH} ${WRKSRC}/clients/mockup.man

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/config

.include <bsd.port.mk>
