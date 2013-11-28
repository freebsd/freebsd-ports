# Created by: Piotr Rybicki (meritus@innervision.pl)
# $FreeBSD$

PORTNAME=	qfaktury
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	polish deskutils
MASTER_SITES=	SF

MAINTAINER=	meritus@innervision.pl
COMMENT=	Polish invoicing desktop program

USES=		qmake
USE_QT4=	uic_build moc_build rcc_build corelib gui xml qt3support

PORTDOCS=	ChangeLog.txt ReadMe.txt ReleaseNotes.txt TODO.txt

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' qfaktury.pro \
	QFaktury.desktop

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
