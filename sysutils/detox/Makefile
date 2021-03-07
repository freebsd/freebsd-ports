# Created by: Doug Harple
# $FreeBSD$

PORTNAME=	detox
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Removes non-standard characters from filenames

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake tar:bzip2
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
GH_ACCOUNT=	dharple

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/detox
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/inline-detox

.include <bsd.port.mk>
