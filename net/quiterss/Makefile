PORTNAME=	quiterss
PORTVERSION=	0.19.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://quiterss.org/files/${PORTVERSION}_/
DISTNAME=	QuiteRSS-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source cross-platform RSS/Atom news feeds reader
WWW=		https://quiterss.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on deprecated www/qt5-webkit
EXPIRATION_DATE=	2023-12-31

USES=		compiler:c++11-lang desktop-file-utils gl pkgconfig \
		qmake:outsource qt:5 sqlite
USE_QT=		buildtools:build linguisttools:build core xml gui widgets \
		network multimedia printsupport webkit sql sql-sqlite3:run
USE_GL=		gl

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=		DEBUG

post-patch-DEBUG-on:
	@${REINPLACE_CMD} 's|debug_and_release|debug|' \
		${WRKSRC}/QuiteRSS.pro

post-patch-DEBUG-off:
	@${REINPLACE_CMD} 's|debug_and_release|release|' \
		${WRKSRC}/QuiteRSS.pro

post-patch:
	@${REINPLACE_CMD} 's|$$$$\[QT_INSTALL_BINS\]/lrelease|${LRELEASE}|' \
		${WRKSRC}/lang/lang.pri
	@${REINPLACE_CMD} 's|$$$$PREFIX/share/quiterss|${DATADIR}|' \
		${WRKSRC}/QuiteRSS.pro

.include <bsd.port.mk>
