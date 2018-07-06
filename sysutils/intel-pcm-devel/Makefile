# Created by: Adrian Chadd
# $FreeBSD$

PORTNAME=	intel-pcm
DISTVERSION=	20180620
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel

MAINTAINER=	egypcio@googlemail.com
COMMENT=	Process Count Monitor (PCM) for Intel processors

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	ignore

ONLY_FOR_ARCHS=	amd64 i386

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	opcm
GH_PROJECT=	pcm
GH_TAGNAME=	7f211c9

CONFLICTS_INSTALL=	intel-pcm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/*.x ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
