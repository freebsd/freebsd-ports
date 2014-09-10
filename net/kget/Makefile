# $FreeBSD$

PORTNAME=	kget
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	net kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE download manager

LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme \
		libktorrent.so:${PORTSDIR}/net-p2p/libktorrent \
		libmms.so:${PORTSDIR}/net/libmms \
		libqca.so:${PORTSDIR}/devel/qca \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs

USE_SQLITE=     yes
USE_KDE4=	kdelibs kdeprefix kdehier workspace libkonq \
		nepomuk-core nepomuk-widgets automoc4 ontologies \
		soprano
USES=		cmake:outsource tar:xz
USE_QT4=	gui sql moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null
CONFIGURE_ENV=	XDG_CONFIG_HOME=/dev/null

.include <bsd.port.mk>
