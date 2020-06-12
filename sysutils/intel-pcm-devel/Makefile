# Created by: Adrian Chadd
# $FreeBSD$

PORTNAME=	intel-pcm
DISTVERSION=	g20200608
PORTEPOCH=	1
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-devel

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Process Count Monitor (PCM) for Intel processors

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

USES=		gmake
USE_GITHUB=	yes

GH_ACCOUNT=	opcm
GH_PROJECT=	pcm
GH_TAGNAME=	b5f69fc

PORTSCOUT=	skipv:202005

CONFLICTS_INSTALL=	intel-pcm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/*.x ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
