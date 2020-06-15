# $FreeBSD$

PORTNAME=	spectral
PORTVERSION=	817
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Glossy Matrix IM client based on Qt technologies

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libqmatrixclient>=0.5.3.2:net-im/libqmatrixclient

USES=		cmake compiler:c++17-lang gl pkgconfig qt:5 tar:bz2
USE_GL=		gl
USE_QT=		core dbus declarative graphicaleffects gui imageformats \
		multimedia network quickcontrols quickcontrols2 svg widgets \
		buildtools_build linguist_build qmake_build

USE_GITLAB=	yes
GL_ACCOUNT=	spectral-im
GL_PROJECT=	spectral \
		SortFilterProxyModel:sfpm
GL_COMMIT=	8d6e69d5529b932b85a2f5e6774de27a267a2ace \
		c61f2bdb0da48804a596a9a3a9382eebdba764dc:sfpm

.include <bsd.port.mk>
