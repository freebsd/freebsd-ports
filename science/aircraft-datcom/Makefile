PORTNAME=	aircraft-datcom
DISTVERSION=	0.0.20120723
PORTREVISION=	7
CATEGORIES=	science

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modified USAF Aircraft Stability and Control Data Compendium
WWW=		https://www.pdas.com/datcom.html

LICENSE=	GPLv3

DEPRECATED=	Ancient software, does not build with CMake 4
EXPIRATION_DATE=2026-11-30

USE_GITHUB=	yes
GH_ACCOUNT=	arktools
GH_TAGNAME=	ed877bb

USES=	fortran cmake
FFLAGS+=	-std=legacy

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
