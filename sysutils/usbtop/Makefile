# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	usbtop
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.2
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utility that shows an estimated instantaneous USB bandwidth

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	aguinet

PLIST_FILES=	sbin/usbtop

.include <bsd.port.mk>
