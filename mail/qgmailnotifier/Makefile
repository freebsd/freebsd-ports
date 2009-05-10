# New ports collection makefile for:	qgmailnotifier
# Date created:		2008-09-12
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qgmailnotifier
PORTVERSION=	2008.3
CATEGORIES=	mail
MASTER_SITES=	http://www.codef00.com/projects/
EXTRACT_SUFX=	.tgz

MAINTAINER=	utisoft@gmail.com
COMMENT=	A portable QT4 based GMail notifier

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build gui network xml rcc_build

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/bin|${PREFIX}/bin|g' ${WRKSRC}/qgmailnotifier.pro

do-configure:
	@cd ${WRKSRC} \
	    && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKE_ARGS} qgmailnotifier.pro

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
