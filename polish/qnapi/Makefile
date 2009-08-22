# New ports collection makefile for:	qnapi
# Date created:		2008-02-15
# Whom:			Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	qnapi
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	polish multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	Unoffical napiprojekt.pl qt4 client

RUN_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui network qmake_build moc_build uic_build rcc_build
INSTALLS_ICONS=	yes

MAN1=		qnapi.1
MANCOMPRESSED=	yes
PORTDOCS=	ChangeLog changelog.gz README README.pl LICENSE \
		LICENSE.pl COPYRIGHT

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' qnapi.pro \
		doc/qnapi.desktop doc/qnapi-download.desktop

pre-build:
	@cd ${WRKSRC} && ${QMAKE} -spec ${QMAKESPEC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
