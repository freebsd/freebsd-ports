# $FreeBSD$

PORTNAME=	kget
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	14
CATEGORIES=	net kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE download manager

LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libktorrent.so:net-p2p/libktorrent-kde4 \
		libmms.so:net/libmms \
		libqca.so:devel/qca@qt4 \
		libboost_thread.so:devel/boost-libs

USES=		cmake:outsource kde:4 qt:4 shebangfix sqlite tar:xz
USE_KDE=	kdelibs workspace libkonq \
		nepomuk-core nepomuk-widgets automoc4 ontologies \
		soprano
SHEBANG_FILES=	conf/*.pl
USE_QT=		gui sql moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null
CONFIGURE_ENV=	XDG_CONFIG_HOME=/dev/null

.include <bsd.port.mk>
