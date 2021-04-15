PORTNAME=	bsdisks
DISTVERSION=	0.26
CATEGORIES=	sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	UDisks2 service implementation for FreeBSD

LICENSE=	BSD3CLAUSE

USES=		cmake compiler:c++11-lang qt:5

USE_QT=		qmake_build buildtools_build core dbus

USE_GITLAB=		yes
GL_SITE=		https://foss.heptapod.net
GL_ACCOUNT=		bsdutils
GL_COMMIT=		e0e705f78ff9ae710eb022941e5e4032619ffcbb
GL_HEPTAPOD_COMMIT=	e1d6cc627e5371f26a3350f19e19f0d1d017b1f2

WRKSRC=		${WRKDIR}/${PORTNAME}-${GL_COMMIT}-${GL_HEPTAPOD_COMMIT}

.include <bsd.port.mk>
