# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	vis2u
PORTVERSION=	1.0
CATEGORIES=	vietnamese textproc
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	VISCII->Unicode conversion

USES=		zip
NO_WRKSUBDIR=	yes

do-build:
	cd ${WRKSRC} ; make vis2u

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vis2u ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

EXTRACT_BEFORE_ARGS+=	-L
