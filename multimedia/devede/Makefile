# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	devede
PORTVERSION=	3.23.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create video DVDs, VCDs, sVCDs, or CVDs from any number of video files

LICENSE=	GPLv3+

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		mencoder:multimedia/mencoder \
		spumux:multimedia/dvdauthor \
		mplayer:multimedia/mplayer \
		vcdimager:multimedia/vcdimager \
		cdrecord:sysutils/cdrtools

NO_ARCH=	yes
USES=		iconv python
NO_BUILD=	yes

OPTIONS_DEFINE=	IBUS NLS
OPTIONS_DEFAULT=	IBUS
IBUS_DESC=	iBus support

DEJAVU_FONTSDIR=	${LOCALBASE}/share/fonts/dejavu
DEJAVU_FONTFILE=	${DEJAVU_FONTSDIR}/DejaVuSans.ttf

IBUS_RUN_DEPENDS=	ibus-daemon:textproc/ibus
NLS_USES=	gettext-runtime:run
OPTIONS_SUB=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rastersoft
GH_PROJECT=	Devede

USE_GNOME=	pygtk2:run
USE_PYTHON=	run

PORTDOCS=	*

post-patch:
# Fix general locations
	@${REINPLACE_CMD} -E \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%PORTNAME%%|${PORTNAME}|' \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		-e 's|%%DOCSDIR%%|${DOCSDIR}|' \
		${WRKSRC}/devede.py
	@${REINPLACE_CMD} -e 's|bash|sh|' ${WRKSRC}/devede-debug
# Fix font location
	@${REINPLACE_CMD} -e \
		's|\(font_path,"\).*\("\)|\1${DEJAVU_FONTFILE}\2|' \
		${WRKSRC}/devede_fonts.py

do-install:
# File locations in devede are a mess...
	${INSTALL_SCRIPT} ${WRKSRC}/devede.py ${STAGEDIR}${PREFIX}/bin/devede
	${INSTALL_SCRIPT} ${WRKSRC}/devede-debug ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/devede
	${INSTALL_DATA} ${WRKSRC}/devede_*.py ${STAGEDIR}${PREFIX}/lib/devede
	${INSTALL_DATA} ${WRKSRC}/devede.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/devedesans.ttf ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/devede.svg ${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/devede.svg ${STAGEDIR}${PREFIX}/share/pixmaps
	(cd ${WRKSRC}/interface && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/pixmaps && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

post-install-NLS-on:
.for i in ca da el es fr gl nl pl pt_BR pt_PT ru sk sv zh_CN zh_TW
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${i}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/devede.mo
.endfor
.for i in cs_CZ de_DE hu_HU it_IT nb_NO
	${INSTALL_DATA} ${WRKSRC}/po/${i}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${i:C/_.*//}/LC_MESSAGES/devede.mo
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/html/* ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
