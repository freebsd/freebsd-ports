PORTNAME=	md5deep
PORTVERSION=	4.4
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Program to compute various message digests recursively
WWW=		https://md5deep.sourceforge.net

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GH_ACCOUNT=	jessek
GH_PROJECT=	hashdeep
GH_TAGNAME=	cd2ed74

USES=		autoreconf compiler:c++11-lang gmake
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
