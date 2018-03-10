# $FreeBSD$

PORTNAME=	aircraft-datcom
DISTVERSION=	0.0.20120723
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Modified USAF Aircraft Stability and Control Data Compendium

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	arktools
GH_TAGNAME=	ed877bb

USES=	fortran cmake

.include <bsd.port.pre.mk>

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
