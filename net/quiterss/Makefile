# Created by: lbartoletti <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quiterss
PORTVERSION=	0.19.4
CATEGORIES=	net
MASTER_SITES=	http://quiterss.org/files/${PORTVERSION}_/
DISTNAME=	QuiteRSS-${PORTVERSION}-src

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Open-source cross-platform RSS/Atom news feeds reader

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang desktop-file-utils gl pkgconfig \
		qmake:outsource qt:5 sqlite
USE_QT=		buildtools_build linguisttools_build core xml gui widgets \
		network multimedia printsupport webkit sql sql-sqlite3_run
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
