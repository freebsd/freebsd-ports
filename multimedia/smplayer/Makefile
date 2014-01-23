# Created by: Diego Depaoli <trebestie@gmail.com> and Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	smplayer
DISTVERSION=	0.8.6
PORTREVISION=	1
CATEGORIES=	multimedia audio kde
MASTER_SITES=	SF/${PORTNAME}/SMPlayer/${PORTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Complete front-end based on Qt4 for mplayer

LICENSE=	GPLv2

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		${LOCALBASE}/share/smplayer/themes:${PORTSDIR}/multimedia/smplayer-skins \
		${LOCALBASE}/share/smplayer/themes:${PORTSDIR}/multimedia/smplayer-themes

USE_QT4=	gui network script xml moc_build rcc_build uic_build \
		uic3_build porting_build linguist_build

ALL_TARGET=	src/smplayer
CONFIGURE_WRKSRC=	${WRKSRC}/src
MAKE_ARGS+=	PREFIX=${PREFIX} DESTDIR=${STAGEDIR}

USE_BZIP2=	yes
USES=		desktop-file-utils dos2unix gmake qmake
DOS2UNIX_REGEX=	.*.[^p][^n][^g]$
INSTALLS_ICONS=	yes

PORTDOCS=	Changelog Not_so_obvious_things.txt Readme.txt \
		Release_notes.txt Watching_TV.txt

OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|&& $$(QMAKE) $$(QMAKE_OPTS)||; \
		s|lrelease|${LRELEASE}|; \
		s|/share/man|/man|g; \
		s| make| ${MAKE_CMD}|g' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
