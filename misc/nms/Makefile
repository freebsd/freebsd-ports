# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nms
PORTVERSION=	20160429
CATEGORIES=	misc

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Recreate decrypting text effect from the Sneakers movie

LICENSE=	GPLv3

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	bartobri
GH_PROJECT=	no-more-secrets
GH_TAGNAME=	9a7a77c
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
