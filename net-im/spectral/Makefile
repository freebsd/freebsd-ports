# $FreeBSD$

PORTNAME=	spectral
PORTVERSION=	464
CATEGORIES=	net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Glossy Matrix IM client based on Qt technologies

LICENSE=	GPLv3
LICENSE_FILES=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libqmatrixclient>=0.5:net-im/libqmatrixclient

USES=		compiler:c++17-lang pkgconfig qmake qt:5 tar:bz2
USE_GL=		gl
USE_QT=		core dbus declarative gui multimedia network widgets \
		buildtools_build linguist_build qmake_build

USE_GITLAB=	yes
GL_ACCOUNT=	b0
GL_PROJECT=	spectral \
		SortFilterProxyModel:sfpm
GL_COMMIT=	0473f25d38a064ee4e18203ec16eeae84fea4866 \
		c61f2bdb0da48804a596a9a3a9382eebdba764dc:sfpm
GL_SUBDIR=	include/SortFilterProxyModel:sfpm

QMAKE_ARGS+=	USE_SYSTEM_QMATRIXCLIENT=true

.include <bsd.port.mk>
