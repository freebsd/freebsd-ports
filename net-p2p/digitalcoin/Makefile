# Created by: myst3r10n <myst3r10n@rocketmail.com>
# $FreeBSD$

PORTNAME=	digitalcoin
PORTVERSION=	1.0.0.0b
PORTREVISION=	5
CATEGORIES=	net-p2p

MAINTAINER=	myst3r10n@rocketmail.com
COMMENT=	Alternative Bitcoin peer-to-peer currency client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
		libminiupnpc.so:${PORTSDIR}/net/miniupnpc

USE_GITHUB=	yes
GH_ACCOUNT=	baritus
GH_TAGNAME=	96b098a

USES=		desktop-file-utils gmake
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	48
USE_QT4=	corelib gui qmake_build linguisttools_build uic_build \
		moc_build rcc_build

PLIST_FILES=	bin/${BINARY} share/applications/digitalcoin-qt.desktop \
		share/pixmaps/digitalcoin.png

BINARY=		digitalcoin-qt

.include <bsd.port.pre.mk>

do-configure:
	cd ${WRKSRC} && ${SETENV} ${QMAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS} USE_UPNP=${QMAKE_USE_UPNP} \
			USE_QRCODE=${QMAKE_USE_QRCODE} \
			QMAKE_LRELEASE=lrelease-qt4 PREFIX=${PREFIX} \
			INCLUDEPATH=${BDB_INCLUDE_DIR} \
			QMAKE_LIBDIR+=${BDB_LIB_DIR} ${PORTNAME}-qt.pro

do-install:
	@${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${STAGEDIR}${PREFIX}/bin/
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		-e 's,bitcoin,digitalcoin,g' \
		-e 's,Bitcoin,Digitalcoin,g' \
		-e 's,xpm,png,g' \
		-e 's,80,,g' ${WRKSRC}/contrib/debian/bitcoin-qt.desktop
	${INSTALL} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop \
	    ${STAGEDIR}${PREFIX}/share/applications/digitalcoin-qt.desktop
	${INSTALL} ${WRKSRC}/src/qt/res/icons/bitcoin.png \
	    ${STAGEDIR}${PREFIX}/share/pixmaps/digitalcoin.png

.include <bsd.port.post.mk>
