# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	vis2u
PORTVERSION=	1.0
CATEGORIES=	vietnamese textproc
MASTER_SITES=	LOCAL/obrien
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VISCII->Unicode conversion

USES=		zip:infozip
NO_WRKSUBDIR=	yes
EXTRACT_BEFORE_ARGS=	-qoL

do-build:
	cd ${WRKSRC} ; make vis2u

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vis2u ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
