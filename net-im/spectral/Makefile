# $FreeBSD$

PORTNAME=	spectral
PORTVERSION=	603
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Glossy Matrix IM client based on Qt technologies

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libqmatrixclient>=0.5:net-im/libqmatrixclient

USES=		compiler:c++17-lang gl pkgconfig qmake qt:5 tar:bz2
USE_GL=		gl
USE_QT=		core dbus declarative graphicaleffects gui imageformats \
		multimedia network quickcontrols2 svg widgets \
		buildtools_build linguist_build qmake_build

USE_GITLAB=	yes
GL_ACCOUNT=	b0
GL_PROJECT=	spectral \
		SortFilterProxyModel:sfpm
GL_COMMIT=	4ef8e1efd95cd8de3f5c215d2ed27754d8e8c11a \
		c61f2bdb0da48804a596a9a3a9382eebdba764dc:sfpm
GL_SUBDIR=	include/SortFilterProxyModel:sfpm

QMAKE_ARGS+=	USE_SYSTEM_QMATRIXCLIENT=true

.include <bsd.port.mk>
