# New ports collection makefile for:	qnapi
# Date created:		2008-02-15
# Whom:			Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	qnapi
PORTVERSION=	0.1.5
PORTREVISION=	4
CATEGORIES=	polish multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Unofficial napiprojekt.pl qt4 client

LICENSE=	GPLv2

RUN_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip

USE_QT4=	corelib gui network qmake_build moc_build uic_build rcc_build
USE_KDE4=	kdehier
QMAKE_ARGS=	PREFIX=${PREFIX} KDE4_PREFIX=${KDE4_PREFIX}
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

MAN1=		qnapi.1
MANCOMPRESSED=	yes
PORTDOCS=	ChangeLog changelog.gz README README.pl LICENSE \
		LICENSE.pl COPYRIGHT

.include <bsd.port.options.mk>

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' \
		doc/qnapi.desktop doc/qnapi-download.desktop
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|@LOCALBASE@|${LOCALBASE}|g' \
		src/napi.h

pre-build:
	@cd ${WRKSRC} && ${QMAKE} -spec ${QMAKESPEC} ${QMAKEFLAGS} ${QMAKE_ARGS}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
