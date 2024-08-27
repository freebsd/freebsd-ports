PORTNAME=	mpc-qt
DISTVERSIONPREFIX=	v
DISTVERSION=	24.06
CATEGORIES=	multimedia audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Media Player Classic Qute Theater
WWW=		https://github.com/mpc-qt/mpc-qt

LICENSE=	GPLv2

BUILD_DEPENDS=	mpv>=0.29,1:multimedia/mpv
LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		compiler:c++14-lang desktop-file-utils pkgconfig qmake qt:6
USE_GITHUB=	yes
USE_QT=		base tools:build
QMAKE_ARGS=	MPCQT_VERSION="${DISTVERSION}${DISTVERSIONSUFFIX}"
LDFLAGS+=	-Wl,--as-needed # GL

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
