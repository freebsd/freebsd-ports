# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qgmailnotifier
DISTVERSION=	2014.2
CATEGORIES=	mail
MASTER_SITES=	GH

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Portable Qt 4 based GMail notifier

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt:4 tar:tgz
USE_QT=		moc_build uic_build gui network xml rcc_build
USE_GITHUB=	yes
GH_ACCOUNT=	eteran

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/bin|${PREFIX}/bin|g' ${WRKSRC}/qgmailnotifier.pro

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
