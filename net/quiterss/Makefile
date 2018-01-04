# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	quiterss
PORTVERSION=	0.18.9
CATEGORIES=	net
MASTER_SITES=	http://quiterss.org/files/${PORTVERSION}/
DISTNAME=	QuiteRSS-${PORTVERSION}-src

MAINTAINER=	lbartoletti@tuxfamily.org
COMMENT=	Open-source cross-platform RSS/Atom news feeds reader

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

NO_WRKSUBDIR=	yes

USES=		desktop-file-utils pkgconfig qmake:outsource sqlite
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		DEBUG
OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	QT4 QT5
OPTIONS_DEFAULT=	QT5

QT4_USE=	QT4=moc_build,rcc_build,uic_build,linguisttools_build
QT4_USE+=	QT4=corelib,gui,network,xml,webkit,phonon,sql,sql-sqlite3_run

QT5_USE=	QT5=buildtools_build,linguisttools_build,core,xml,gui,widgets
QT5_USE+=	QT5=network,multimedia,printsupport,webkit,sql,sql-sqlite3_run

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
