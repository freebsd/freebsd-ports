# $FreeBSD$

PORTNAME=	aircraft-datcom
DISTVERSION=	0.0.20120723
PORTREVISION=	3
CATEGORIES=	science

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Modified USAF Aircraft Stability and Control Data Compendium

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	arktools
GH_TAGNAME=	ed877bb

USES=	fortran cmake

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
