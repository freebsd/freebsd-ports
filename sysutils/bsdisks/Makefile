# $FreeBSD$

PORTNAME=	bsdisks
DISTVERSION=	0.25
CATEGORIES=	sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	UDisks2 service implementation for FreeBSD

LICENSE=	BSD3CLAUSE

USES=		cmake compiler:c++11-lang qt:5

USE_QT=		qmake_build buildtools_build core dbus

USE_GITLAB=		yes
GL_SITE=		https://foss.heptapod.net
GL_ACCOUNT=		bsdutils
GL_COMMIT=		dd9da45ed4b779d782b9a0b4f35cd029c0c0db25
GL_HEPTAPOD_COMMIT=	c3a040afa0d0f01116917e50d16b0cdd383334bd

WRKSRC=		${WRKDIR}/${PORTNAME}-${GL_COMMIT}-${GL_HEPTAPOD_COMMIT}

.include <bsd.port.mk>
