# $FreeBSD$

PORTNAME=	signify
PORTVERSION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.fefe.de/signify/
DISTNAME=	${PORTNAME}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	OpenBSD signify ported by Felix von Leitner

LICENSE=	BSD2CLAUSE

USES=		gmake compiler:c11

PLIST_FILES=	bin/signify

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/signify ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
