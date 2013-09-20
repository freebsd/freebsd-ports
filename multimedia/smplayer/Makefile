# Created by: Diego Depaoli <trebestie@gmail.com> and Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	smplayer
DISTVERSION=	0.8.5
CATEGORIES=	multimedia audio kde
MASTER_SITES=	SF/${PORTNAME}/SMPlayer/${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Complete front-end based on Qt4 for mplayer

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		${LOCALBASE}/share/smplayer/themes:${PORTSDIR}/multimedia/smplayer-themes

USE_QT4=	gui network xml qmake_build moc_build rcc_build uic_build \
		uic3_build porting_build linguist_build

ALL_TARGET=	src/smplayer

MAKE_JOBS_UNSAFE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes

MAN1=		smplayer.1
MANCOMPRESSED=	yes

PORTDOCS=	Changelog Copying.txt Install.txt Not_so_obvious_things.txt \
		Readme.txt Release_notes.txt

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|qmake|${QMAKE}|g' \
		-e 's|lrelease|${QT_PREFIX}/bin/lrelease-qt4|g' \
		-e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|g' \
		-e 's,/share/man,/man,g' \
		${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
