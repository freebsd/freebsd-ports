# $FreeBSD$

PORTNAME=	tigervnc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
CATEGORIES=	net x11-servers

MAINTAINER?=	meta@FreeBSD.org

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENCE.TXT

USES+=		cmake:insource,noninja
USE_GITHUB=	yes

GH_ACCOUNT=	TigerVNC

CONFLICTS=	tightvnc-[0-9]*

CMAKE_ARGS+=	-G "Unix Makefiles"
MAKE_ARGS+=	TIGERVNC_SRCDIR=${WRKSRC}

.include <bsd.port.pre.mk>

PLIST=	${.CURDIR}/pkg-plist

.include <bsd.port.post.mk>
