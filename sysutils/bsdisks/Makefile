# $FreeBSD$

PORTNAME=	bsdisks
DISTVERSION=	0.24
CATEGORIES=	sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	UDisks2 service implementation for FreeBSD

LICENSE=	BSD3CLAUSE

USES=		cmake compiler:c++11-lang qt:5

USE_QT=		qmake_build buildtools_build core dbus

USE_GITLAB=		yes
GL_SITE=		https://foss.heptapod.net
GL_ACCOUNT=		bsdutils
GL_COMMIT=		6ee813b8ddba4e8c7958c712575b62b796c1fb60
GL_HEPTAPOD_COMMIT=	6c7c24aad721fde62ccea3aa82a41c83d5b4f040

WRKSRC=		${WRKDIR}/${PORTNAME}-${GL_COMMIT}-${GL_HEPTAPOD_COMMIT}

.include <bsd.port.mk>
